#include "libpq-fe.h"

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
	
};

