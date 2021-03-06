#pragma once
#define _SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#define USE_BOOST_ASIO 1
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#define _ENABLE_EXTENDED_ALIGNED_STORAGE

#include <Windows.h>

#include "../NM_ClientSDK/NoMercy.h"

class CNoMercy
{
	public:
		// Initilization
		void InitTest(bool bClient); // Test only, Standalone app
		bool InitCore(const char* c_szLicenseCode, LPCVOID c_pModuleInfo, bool bStandaloneProcess); // Client, Core wrapper from SDK/DLL
		bool InitMasterServer(WORD wPort); // Master Server
		bool InitLauncher(HINSTANCE hInstance, const char* c_szLicenseCode, LPCVOID c_pModuleInfo, bool bProtected); // Launcher
		bool InitService(bool bProtected, LPCVOID c_pModuleInfo); // Service
		bool InitShadow(HMODULE hModule, HWND hWnd, HINSTANCE hInstance, LPSTR lpszCmdLine, int nCmdShow); // Shadow app(aka. rundll)
		bool InitHelper(LPCVOID c_pModuleInfo); // Helper app

		// Finalization
		bool Release();

		// Utils
		bool CreateMessageHandler(TNMCallback lpMessageHandler);
		bool SendNMMessage(int Code, LPVOID lpMessage);

		void OnGameTick();
		void OnServiceMessage(int iMessageID);
};

