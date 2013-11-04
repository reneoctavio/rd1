#include "stdafx.h"
#include "Database.h"
#include "libpq-fe.h"
#include <string>
#include <sstream>
#include <ctime>

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
		_res = PQexec(_conn, "CREATE TABLE CLP (PKEY SERIAL PRIMARY KEY, R INTEGER[10], M INTEGER[5], D REAL[5], TIME TIMESTAMP)");
	}

	if ((PQresultStatus(_res) == ExecStatusType::PGRES_TUPLES_OK) || (PQresultStatus(_res) == ExecStatusType::PGRES_COMMAND_OK))
	{
		PQclear(_res);
		return true;
	}
	PQclear(_res);
	return false;
}

bool Database::InsertEntry(unsigned char *bufferR, short int *bufferM, float *bufferD)
{
	// Append the SQL statment
	std::string sSQL;
	sSQL.append("INSERT INTO clp (r, m, d, \"time\") VALUES('");

	// BUFFER R
	sSQL.append("{");
	for (int i = 0; i < PARAM_R_NUM_VAL; i++)
	{
		int r = bufferR[i];
		std::stringstream ss;
		ss.flush();
		ss << r;
		sSQL.append(ss.str());
		if (i == (PARAM_R_NUM_VAL - 1)) break;
		sSQL.append(", ");
	}
	sSQL.append("}");
	
	// BUFFER M
	sSQL.append("', '{");
	for (int i = 0; i < PARAM_M_NUM_VAL; i++)
	{
		std::stringstream ss;
		ss.flush();
		ss << bufferM[i];
		sSQL.append(ss.str());
		if (i == (PARAM_M_NUM_VAL - 1)) break;
		sSQL.append(", ");
	}
	sSQL.append("}");

	// BUFFER D
	sSQL.append("', '{");
	for (int i = 0; i < PARAM_D_NUM_VAL; i++)
	{
		std::ostringstream oss;
		oss.flush();
		oss << bufferD[i];
		sSQL.append(oss.str());
		if (i == (PARAM_D_NUM_VAL - 1)) break;
		sSQL.append(", ");
	}
	sSQL.append("}', '");

	// TIMESTAMP
	std::time_t t = std::time(NULL);
	sSQL.append(std::asctime(std::localtime(&t)));

	sSQL.append("')");

	// Execute with sql statement
	_res = PQexec(_conn, sSQL.c_str());

	if (PQresultStatus(_res) != PGRES_COMMAND_OK)
	{
		PQclear(_res);
		return false;
	}

	// Clear result
	PQclear(_res);
	return true;
}