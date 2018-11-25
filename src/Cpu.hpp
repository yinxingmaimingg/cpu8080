#ifndef CPU8080
#define CPU8080

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <chrono>
#include <thread>
#include <bitset>
#include <iostream>

#include "SDL2/SDL.h"

using namespace std;

typedef struct ConditionCodes {
	uint8_t		z:1;
	uint8_t		s:1;
	uint8_t		p:1;
	uint8_t		cy:1;
	uint8_t		ac:1;
	uint8_t		pad:3;
} ConditionCodes;

// ConditionCodes CC_ZSPAC = {1,1,1,0,1};

typedef struct State8080 {
	uint8_t		a;
	uint8_t		b;
	uint8_t		c;
	uint8_t		d;
	uint8_t		e;
	uint8_t		h;
	uint8_t		l;
	uint16_t	sp;
	uint16_t	pc;
	uint8_t		*memory;
	struct ConditionCodes cc;
	uint8_t		int_enable;
}State8080;

int parity(int x, int size);
State8080* Init8080(void);
void ReadFileIntoMemoryAt(State8080* state, char* filename, uint32_t offset);
void GenerateInterrupt(State8080* state, int interrupt_num);

int Disassemble8080Op(unsigned char *codebuffer, int pc);

void LogicFlagsA(State8080 *state);

void ArithFlagsA(State8080 *state, uint16_t res);

void UnimplementedInstruction(State8080* state);

int Emulate8080Op(State8080* state);


#endif