#include "StdAfx.h"
#include "ConnManager.h"
#include <iostream>

namespace rd1 {
	ConnManager::ConnManager(void)
	{
		LoadLib();
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

	int ConnManager::OpenPort(void)
	{
		return ((SCPOpenPortPtr)GetProcAddress(GetLib(), "SCPOpenPort")) ("ScpHi.cfg");
	}

	int ConnManager::ClosePort(void)
	{
		return ((SCPClosePortPtr)GetProcAddress(GetLib(), "SCPClosePort")) ();
	}

	int ConnManager::Release(int &version, int &revision)
	{
		return ((SCPReleasePtr)GetProcAddress(GetLib(), "SCPRelease")) (version, revision);
	}

	int ConnManager::ResetDriver(void)
	{
		return ((SCPResetDriverPtr)GetProcAddress(GetLib(), "SCPResetDriver")) ();
	}

	int ConnManager::GetComTimeout(int &timeout)
	{
		return ((SCPGetComTimeoutPtr)GetProcAddress(GetLib(), "SCPGetComTimeout")) (timeout);
	}

	int ConnManager::SetComTimeout(int timeout)
	{
		return ((SCPSetComTimeoutPtr)GetProcAddress(GetLib(), "SCPSetComTimeout")) (timeout);
	}

	int ConnManager::ModemResetOperation(void)
	{
		return ((SCPModemResetOperationPtr)GetProcAddress(GetLib(), "SCPModemResetOperation")) ();
	}

	int ConnManager::ModemCheckOperation(void)
	{
		return ((SCPModemCheckOperationPtr)GetProcAddress(GetLib(), "SCPModemCheckOperation")) ();
	}

	int ConnManager::ModemConnect(char *phoneNumber)
	{
		return ((SCPModemConnectPtr)GetProcAddress(GetLib(), "SCPModemConnect")) (phoneNumber);
	}

	int ConnManager::ModemDisconnect(void)
	{
		return ((SCPModemDisconnectPtr)GetProcAddress(GetLib(), "SCPModemDisconnect")) ();
	}

	int ConnManager::CheckConnection(int ctrlNumber)
	{
		return ((SCPCheckConnectionPtr)GetProcAddress(GetLib(), "SCPCheckConnetion")) (ctrlNumber);
	}

	int ConnManager::ReadData(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
		void *DataBuf)
	{
		return ((SCPReadDataPtr)GetProcAddress(GetLib(), "SCPReadData")) (CtrlNumber, TypeVar, VarIni, VarQuant, DataBuf);
	}

	int ConnManager::WriteData(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
		void *DataBuf)
	{
		return ((SCPWriteDataPtr)GetProcAddress(GetLib(), "SCPWriteData")) (CtrlNumber, TypeVar, VarIni, VarQuant, DataBuf);
	}

	int ConnManager::ModemAutoAnswer(int state)
	{
		return ((SCPModemAutoAnswerPtr)GetProcAddress(GetLib(), "SCPModemAutoAnswer")) (state);
	}

	int ConnManager::ConfigComChannel(char *configFileName)
	{
		return ((SCPConfigComChannelPtr)GetProcAddress(GetLib(), "SCPConfigComChannel")) (configFileName);
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