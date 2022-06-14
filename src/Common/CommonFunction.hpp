#pragma once

#ifndef SWAP(a, b) 
	#define SWAP(a, b)\
		a = a ^ b; \
		b = b ^ a; \
		a = a ^ b;
#endif

inline int Abs(int num)
{
	return ~num + 1;
}