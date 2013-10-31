#include <Windows.h>

#pragma once
namespace rd1 {

	typedef int(WINAPI *SCPOpenPortPtr)(char *cfg);
	typedef int(WINAPI *SCPClosePortPtr)(void);
	typedef int(WINAPI *SCPReleasePtr)(int &version, int &revision);
	typedef int(WINAPI *SCPResetDriverPtr)();
	typedef int(WINAPI *SCPGetComTimeoutPtr)(int &timeout);
	typedef int(WINAPI *SCPSetComTimeoutPtr)(int timeout);
	typedef int(WINAPI *SCPModemResetOperationPtr)(void);
	typedef int(WINAPI *SCPModemCheckOperationPtr)(void);
	typedef int(WINAPI *SCPModemConnectPtr)(char *phoneNumber);
	typedef int(WINAPI *SCPModemDisconnectPtr)(void);
	typedef int(WINAPI *SCPCheckConnectionPtr)(int ctrlNumber);
	typedef int(WINAPI *SCPReadDataPtr)(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
		void* DataBuf);

	typedef int(WINAPI *SCPWriteDataPtr)(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
		void* DataBuf);

	typedef int(WINAPI *SCPModemAutoAnswerPtr)(int state);
	typedef int(WINAPI *SCPConfigComChannelPtr)(char *configFileName);

	ref class ConnManager
	{
	public:
		ConnManager(void);
		void ConnManager::FreeLib(void);

		// Abstraction of the DLL
		int ConnManager::OpenPort(void);
		int ConnManager::ClosePort(void);
		int ConnManager::Release(int &version, int &revision);
		int ConnManager::ResetDriver(void);
		int ConnManager::GetComTimeout(int &timeout);
		int ConnManager::SetComTimeout(int timeout);
		int ConnManager::ModemResetOperation(void);
		int ConnManager::ModemCheckOperation(void);
		int ConnManager::ModemConnect(char *phoneNumber);
		int ConnManager::ModemDisconnect(void);
		int ConnManager::CheckConnection(int ctrlNumber);
		int ConnManager::ReadData(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
			void *DataBuf);

		int ConnManager::WriteData(int CtrlNumber, int TypeVar, int VarIni, int VarQuant,
			void *DataBuf);

		int ConnManager::ModemAutoAnswer(int state);
		int ConnManager::ConfigComChannel(char *configFileName);

		// Added Functionality
		int ConnManager::ReadDataParamR(unsigned char *DataBuf);
		int ConnManager::ReadDataParamM(short int *DataBuf);
		int ConnManager::ReadDataParamD(float *DataBuf);

		int ConnManager::WriteDataParamR(unsigned char *DataBuf);
		int ConnManager::WriteDataParamM(short int *DataBuf);
		int ConnManager::WriteDataParamD(float *DataBuf);

	private:
		HMODULE ConnManager::GetLib(void);
		bool ConnManager::LoadLib(void);
		
		HMODULE _lib;
	};

}