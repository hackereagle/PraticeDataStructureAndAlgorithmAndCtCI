#pragma once

#ifndef SWAP 
	#define SWAP(a, b)\
		a = a ^ b; \
		b = b ^ a; \
		a = a ^ b;
#endif

inline int Abs(int num)
{
	return ~num + 1;
}