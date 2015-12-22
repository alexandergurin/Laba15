// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LOG_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LOG_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.


#include <iostream>
#include <Windows.h>

extern "C" __declspec(dllexport) std::string getSize2();

class  Log2;


class Log2
{
public:
	Log2();
	virtual ~Log2();
	virtual std::string write2();
};
extern "C" __declspec(dllexport)  Log2* GetPointer2();