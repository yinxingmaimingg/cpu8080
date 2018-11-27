#ifndef INTEL8080
#define INTEL8080

#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>

#include "InvadersIO.hpp"

using namespace std;

const int WIDTH = 224;
const int HEIGHT = 256;

typedef struct ConditionCodes {
	bool z, s, p, c, ac;
} Flags;


class Intel8080 {
public:
	Intel8080(InvadersIO* device);
	~Intel8080();
	void loadFile(string filename);
	void getPixels(uint32_t *pixels);
	void mainLoop();
	void generateInterrupt(uint16_t inte_num);
	void printStatus();

	static uint16_t combInt8(uint8_t high_val, uint8_t low_val);
	uint16_t pc;		// program counter

	int debug_enable = false;

private:
	// hardware
	uint8_t	a, b, c, d, e, h, l;	// main registers 
	uint16_t sp;		// stack pointer
	uint8_t *memory;
	Flags flags;
	bool int_enable; 	// whether interrupt is enabled
	uint8_t *opcode; 	// current opcde location

	int opcodeCounter; 	// for debug

	// input & output device
	InvadersIO * dev_io;
	
	void unimplementedInstruction();
	bool getParity(int x, int size);
	uint8_t* getReg3(uint8_t reg3);
	uint8_t* getReg2Addr1(uint8_t reg2);
	uint8_t* getReg2Addr2(uint8_t reg2);
	bool checkFlag();
	void updateZSP(uint8_t result);
	void updateCZSP(uint16_t result);
	uint8_t splitInt16High(uint16_t val);
	uint8_t splitInt16Low(uint16_t val);

	uint16_t memoryRW(uint16_t pos);
	void memoryWW(uint16_t pos, uint16_t val);
	void pushW(uint16_t val);
	void pushB(uint8_t val);
	uint8_t popB();
	uint16_t popW();
	void arith(uint8_t val);

	void jump();
	void call();
	void ret();

	void opADI(uint8_t val);
	void opACI(uint8_t val);
	void opSUI(uint8_t val);
	void opSBI(uint8_t val);
	void opANI(uint8_t val);
	void opXRI(uint8_t val);
	void opORI(uint8_t val);
	void opCPI(uint8_t val);

	void opINR();
	void opDCR();
	void opCMA();
	void opDAA();

	void opPCHL();
	void opJMP();
	void opCALL();
	void opRET();
	void opMOV();

	void opSTAX();
	void opLDAX();

	void opPUSH();
	void opPOP();
	void opDAD();
	void opINX();
	void opDCX();

	void opXCHG();
	void opXTHL();
	void opSPHL();

	void opSTA();
	void opLDA();
	void opSHLD();
	void opLHLD();

	void opLXI();
	void opMVI();
	void opROT();

	void opCMC();
	void opSTC();

	void opREMEARITH();
	void opIMMEARITH();

	void opRST();
	void opEI();
	void opDI();

	void opIN();
	void opOUT();

	void disassemble();

	const uint8_t maskINR   = 0xC7;
	const uint8_t checkINR  = 0x04;

	const uint8_t maskDCR   = 0xC7;
	const uint8_t checkDCR  = 0x05;

	const uint8_t maskMOV   = 0xC0;
	const uint8_t checkMOV  = 0x40;

	const uint8_t maskJMP   = 0xC7;
	const uint8_t checkJMP  = 0xC2;

	const uint8_t maskCALL  = 0xC7;
	const uint8_t checkCALL = 0xC4;

	const uint8_t maskRET   = 0xC7;
	const uint8_t checkRET  = 0xC0;

	const uint8_t maskPUSH  = 0xCF;
	const uint8_t checkPUSH = 0xC5;

	const uint8_t maskPOP   = 0xCF;
	const uint8_t checkPOP  = 0xC1;

	const uint8_t maskDAD   = 0xCF;
	const uint8_t checkDAD  = 0x09;

	const uint8_t maskINX   = 0xCF;
	const uint8_t checkINX  = 0x03;

	const uint8_t maskDCX   = 0xCF;
	const uint8_t checkDCX  = 0x0B;

	const uint8_t maskLXI   = 0xCF;
	const uint8_t checkLXI  = 0x01;

	const uint8_t maskMVI   = 0xC7;
	const uint8_t checkMVI  = 0x06;

	const uint8_t maskROT   = 0xE7;
	const uint8_t checkROT  = 0x07;

	const uint8_t maskREMEARITH   = 0xC0;
	const uint8_t checkREMEARITH  = 0x80;

	const uint8_t maskIMMEARITH   = 0xC7;
	const uint8_t checkIMMEARITH  = 0xC6;

	const uint8_t maskRST 	= 0xC7;
	const uint8_t checkRST 	= 0xC7;
};

#endif