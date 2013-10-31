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
		this->_lib = LoadLibraryA("..\\ScpHIV10.dll");
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
		return ((SCPOpenPortPtr)GetProcAddress(GetLib(), "SCPOpenPort")) ("..\\ScpHi.cfg");
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

	/// <summary>
	/// Read Data from Parameter R.
	/// From R11 to R20
	/// </summary>
	int ConnManager::ReadDataParamR(unsigned char *DataBuf)
	{
		return ReadData(1, 0, 11, 10, DataBuf);
	}

	/// <summary>
	/// Read Data from Parameter M.
	/// From M6 to M10
	/// </summary>
	int ConnManager::ReadDataParamM(short int *DataBuf)
	{
		return ReadData(1, 1, 6, 5, DataBuf);
	}

	/// <summary>
	/// Read Data from Parameter D.
	/// From D4 to D8
	/// </summary>
	int ConnManager::ReadDataParamD(float *DataBuf)
	{
		return ReadData(1, 2, 4, 5, DataBuf);
	}

	/// <summary>
	/// Write Data of Parameter R.
	/// From R11 to R20
	/// </summary>
	int ConnManager::WriteDataParamR(unsigned char *DataBuf)
	{
		return WriteData(1, 0, 11, 10, DataBuf);
	}

	/// <summary>
	/// Write Data of Parameter M.
	/// From M6 to M10
	/// </summary>
	int ConnManager::WriteDataParamM(short int *DataBuf)
	{
		return WriteData(1, 1, 6, 5, DataBuf);
	}

	/// <summary>
	/// Write Data of Parameter D.
	/// From D4 to D8
	/// </summary>
	int ConnManager::WriteDataParamD(float *DataBuf)
	{
		return WriteData(1, 2, 4, 5, DataBuf);
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