#include "stdafx.h"
#include "Parameters.h"

namespace rd1{
	Parameters::Parameters()
	{
		InitializeArrays();
	}

	Parameters::~Parameters()
	{
		delete this->bufferR;
		delete this->bufferM;
		delete this->bufferD;
	}

	void Parameters::InitializeArrays(void)
	{
		this->bufferR = new unsigned char[PARAM_R_NUM_VAL];
		this->bufferM = new short int[PARAM_M_NUM_VAL];
		this->bufferD = new float[PARAM_D_NUM_VAL];
	}

	void Parameters::ResetBuffers(void)
	{
		// Zero buffer R
		for (int i = 0; i < PARAM_R_NUM_VAL; i++)
		{
			bufferR[i] = 0;
		}

		// Zero buffer M
		for (int i = 0; i < PARAM_M_NUM_VAL; i++)
		{
			bufferM[i] = 0;
		}

		// Zero buffer D
		for (int i = 0; i < PARAM_D_NUM_VAL; i++)
		{
			bufferD[i] = 0.0;
		}
	}

	unsigned char * Parameters::GetBufferR(void)
	{
		return this->bufferR;
	}

	short int * Parameters::GetBufferM(void)
	{
		return this->bufferM;
	}

	float * Parameters::GetBufferD(void)
	{
		return this->bufferD;
	}

	void Parameters::SetBufferR(void *buffer)
	{
		this->bufferR = (unsigned char*) buffer;
	}

	void Parameters::SetBufferM(void *buffer)
	{
		this->bufferM = (short int*)buffer;
	}

	void Parameters::SetBufferD(void *buffer)
	{
		this->bufferD = (float*)buffer;
	}

	void Parameters::SetParamRAtPos(int pos, unsigned char value)
	{
		bufferR[pos - PARAM_R_POS_VAL_INI] = value;
	}

	void Parameters::SetParamMAtPos(int pos, short int value)
	{
		bufferM[pos - PARAM_M_POS_VAL_INI] = value;
	}

	void Parameters::SetParamDAtPos(int pos, float value)
	{
		bufferD[pos - PARAM_D_POS_VAL_INI] = value;
	}

	unsigned char Parameters::GetParamRAtPos(int pos)
	{
		return bufferR[pos - PARAM_R_POS_VAL_INI];
	}

	short int Parameters::GetParamMAtPos(int pos)
	{
		return bufferM[pos - PARAM_M_POS_VAL_INI];
	}

	float Parameters::GetParamDAtPos(int pos)
	{
		return bufferD[pos - PARAM_D_POS_VAL_INI];
	}
}
