#include <Windows.h>

#pragma once
namespace rd1 {

	typedef int(WINAPI *SCPOpenPortPtr)(char *cfg);

	ref class ConnManager
	{
	public:
		ConnManager(void);
		void ConnManager::FreeLib(void);
		
		
	private:
		HMODULE ConnManager::GetLib(void);
		bool ConnManager::LoadLib(void);
		void ConnManager::ConfigProcAddress(void);
		
		HMODULE _lib;
		SCPOpenPortPtr _SCPOpenPort;
	};

}