#include <windows.h>
#include <iostream>
#include "Lib.h"
#include "string"
#include <iphlpapi.h>
#include <stdio.h>

extern "C" __declspec(dllexport) std::string  getSize()
{
	// ��� ��������� �� ������� GetAdaptersInfo
	typedef DWORD(CALLBACK* PTR_GETADAPTERSINFO)(PIP_ADAPTER_INFO, PULONG);

	// �������� ���������� iphlpapi.dll. ��� win95 ������ ����� � �� ���������.
	HINSTANCE iphlpapi;
	iphlpapi = LoadLibrary(L"iphlpapi.dll");
	if (!iphlpapi)
	{
		printf("iphlpapi.dll �� ��������������\n");
		//return L"";
	}

	PTR_GETADAPTERSINFO GetAdaptersInfo;
	GetAdaptersInfo = (PTR_GETADAPTERSINFO)GetProcAddress(iphlpapi,
		"GetAdaptersInfo");
	ULONG adapter_info_size = 0;
	PIP_ADAPTER_INFO ptr_adapter_info = NULL;
	PIP_ADAPTER_INFO ptr_adapter_info_first = NULL;

	GetAdaptersInfo(ptr_adapter_info, &adapter_info_size);

	ptr_adapter_info_first = ptr_adapter_info = (PIP_ADAPTER_INFO) new(
		char[adapter_info_size]);

	if (GetAdaptersInfo(ptr_adapter_info, &adapter_info_size) != ERROR_SUCCESS)
	{
		printf("Error while GetAdaptersInfo\n");
		delete(ptr_adapter_info);
		//		return L"";
	}


	printf("MAC address: ");


	std::string s;

	for (char i = 0; i < (int)ptr_adapter_info->AddressLength; i++)
	{
		char buff[100];
		snprintf(buff, sizeof(buff), "%02x", (unsigned char)ptr_adapter_info->Address[i]);
		std::string buffAsStdStr = buff;
		s += buffAsStdStr + '-';
	}


	s.erase(s.end() - 1);



	delete(ptr_adapter_info_first);
	char a = getchar();
	return s;

}




Log* GetPointer()
{
	return new Log;
}

Log::Log()
{
}
Log::~Log()
{
}

std::string Log::write()
{
	// ��� ��������� �� ������� GetAdaptersInfo
	typedef DWORD(CALLBACK* PTR_GETADAPTERSINFO)(PIP_ADAPTER_INFO, PULONG);

	// �������� ���������� iphlpapi.dll. ��� win95 ������ ����� � �� ���������.
	HINSTANCE iphlpapi;
	iphlpapi = LoadLibrary(L"iphlpapi.dll");
	if (!iphlpapi)
	{
		printf("iphlpapi.dll �� ��������������\n");
		//return L"";
	}

	PTR_GETADAPTERSINFO GetAdaptersInfo;
	GetAdaptersInfo = (PTR_GETADAPTERSINFO)GetProcAddress(iphlpapi,
		"GetAdaptersInfo");
	ULONG adapter_info_size = 0;
	PIP_ADAPTER_INFO ptr_adapter_info = NULL;
	PIP_ADAPTER_INFO ptr_adapter_info_first = NULL;

	GetAdaptersInfo(ptr_adapter_info, &adapter_info_size);

	ptr_adapter_info_first = ptr_adapter_info = (PIP_ADAPTER_INFO) new(
		char[adapter_info_size]);

	if (GetAdaptersInfo(ptr_adapter_info, &adapter_info_size) != ERROR_SUCCESS)
	{
		printf("Error while GetAdaptersInfo\n");
		delete(ptr_adapter_info);
		//		return L"";
	}


	printf("MAC address: ");


	std::string s;

	for (char i = 0; i < (int)ptr_adapter_info->AddressLength; i++)
	{
		char buff[100];
		snprintf(buff, sizeof(buff), "%02x", (unsigned char)ptr_adapter_info->Address[i]);
		std::string buffAsStdStr = buff;
		s += buffAsStdStr + '-';
	}


	s.erase(s.end() - 1);



	delete(ptr_adapter_info_first);
	char a = getchar();
	return s;
}
