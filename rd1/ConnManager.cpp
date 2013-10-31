#include "StdAfx.h"
#include "ConnManager.h"

namespace rd1 {
	ConnManager::ConnManager(void)
	{
		LoadLib();
		ConfigProcAddress();
	}

	bool ConnManager::LoadLib(void)
	{
		this->_lib = LoadLibraryA("ScpHIV10");
		if (this->_lib != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ConnManager::ConfigProcAddress(void)
	{
		this->_SCPOpenPort = (SCPOpenPortPtr)GetProcAddress(GetLib(), "SCPOpenPort");
	}

	void ConnManager::FreeLib(void)
	{
		if (this->_lib != NULL)
			FreeLibrary(GetLib());
	}

	HMODULE ConnManager::GetLib(void)
	{
		return this->_lib;
	}
}