#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include "scLog.h"

// ********** testing codes **********************
class Test
{
public:
	Test()
	{
		;
	}
	~Test() { ; }
	void GetFunctionName()
	{
		std::cout << "in " << __FUNCTION__ << std::endl;
	}

	void _TestBuiltFunction(const char* func)
	{
		std::cout << func << std::endl;
	}

};

#define TestBuiltFunction() _TestBuiltFunction(__FUNCTION__) 

void WriteFormatted(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// ************ Test Codes End **********************

int main()
{
	Test* t = new Test();
	t->GetFunctionName();
	t->TestBuiltFunction();

	WriteFormatted("Call with %d variable argument.\n", 1);
	WriteFormatted("Call with %d variable %s.\n", 2, "arguments");

	initialLog();
	scLog(LogLevels::LOGDEBUG, "test", __FUNCTION__);

	system("pause");
	return 1;
}