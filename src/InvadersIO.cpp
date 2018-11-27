#include "InvadersIO.hpp"
#include "Intel8080.hpp"

using namespace std;

InvadersIO::InvadersIO()
		: port1(0x01<<3)	// bit 3 always 1
		, port2(0x00)
		, shift0(0x00)
		, shift1(0x00)
		, shift_offset(0x00)
{}

InvadersIO::~InvadersIO() {}


uint8_t InvadersIO::machineIn(uint8_t port) {
	switch (port) {
		case 0x01: return port1;
		case 0x02: return port2;
		case 0x03:
		{
			uint16_t temp16 = Intel8080::combInt8(shift1, shift0);
			return (uint8_t) ((temp16 >> (8 - shift_offset)) & 0xFF);
		}
		default:
			cout<<"ERROR: Unknown IN port "<<dec<<(int)port<<endl;
	}
}

void InvadersIO::machineOut(uint8_t port, uint8_t val) {
	switch (port) {
		case 0x02:
			shift_offset = val & 0x07;
			break;
		case 0x03:
			// cout<<"Play sound"<<endl;
			break;
		case 0x04:
			shift0 = shift1;
			shift1 = val;
			break;
		case 0x05:
			// cout<<"Play sound"<<endl;
			break;
		case 0x06:
			// debug port;
			break;
		default:
			cout<<"ERROR: Unknown OUT port "<<dec<<(int)port<<endl;
	}
}

void InvadersIO::setPort1(int bit, bool val) {
	if (val) {
		port1 |= 1 << bit;
	} else {
		port1 &= (~(1 << bit)) & 0xFF;
	}
}

void InvadersIO::setPort2(int bit, bool val) {
	if (bit==2 || bit==7) {
		port2 ^= 1 << bit;
	} else {
		if (val) {
			port2 |= 1 << bit;
		} else {
			port2 &= (~(1 << bit)) & 0xFF;
		}
	}
}


