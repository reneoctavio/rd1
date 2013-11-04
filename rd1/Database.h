#include "libpq-fe.h"

const static int PARAM_R_NUM_VAL = 10;
const static int PARAM_M_NUM_VAL = 5;
const static int PARAM_D_NUM_VAL = 5;

#pragma once
ref class Database
{
private:
	bool Database::Connect(void);
	bool Database::CreateTable(void);
	void Database::CloseConn(void);

	PGconn *_conn;
	PGresult *_res;
public:
	Database();
	bool Database::InsertEntry(unsigned char *bufferR, short int *bufferM, float *bufferD);
};

