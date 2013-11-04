#include "stdafx.h"
#include "Database.h"
#include "libpq-fe.h"

Database::Database()
{
	if (Connect())
		CreateTable();
}

/* Close connection to database */
void Database::CloseConn(void)
{
	PQfinish(_conn);
}

bool Database::Connect(void)
{
	_conn = PQconnectdb("user=postgres password=12345 dbname=postgres hostaddr=127.0.0.1 port=5432");
	if (PQstatus(_conn) == ConnStatusType::CONNECTION_OK)
	{
		return true;
	}
	CloseConn();
	return false;
}

bool Database::CreateTable(void)
{
	// Check if table exist, if not create it.
	_res = PQexec(_conn, "SELECT * FROM CLP");

	if (PQresultStatus(_res) == ExecStatusType::PGRES_FATAL_ERROR){
		_res = PQexec(_conn, "CREATE TABLE CLP (PKEY SERIAL PRIMARY KEY, R VARCHAR(10), M INTEGER[5], D REAL[5], TIME TIMESTAMP)");
	}

	if ((PQresultStatus(_res) == ExecStatusType::PGRES_TUPLES_OK) || (PQresultStatus(_res) == ExecStatusType::PGRES_COMMAND_OK))
	{
		PQclear(_res);
		return true;
	}
	PQclear(_res);
	return false;
}