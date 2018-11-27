#ifndef INVADERSIO
#define INVADERSIO

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class InvadersIO {
public:
	InvadersIO();
	~InvadersIO();
	uint8_t machineIn(uint8_t port);
	void machineOut(uint8_t port, uint8_t val);
	void setPort1(int bit, bool val);
	void setPort2(int bit, bool val);

private:
	uint8_t port1, port2;
	uint8_t shift0, shift1, shift_offset;

};

#endif
