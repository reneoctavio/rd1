#pragma once
namespace rd1{

	const static int PARAM_R_NUM_VAL = 10;
	const static int PARAM_M_NUM_VAL = 5;
	const static int PARAM_D_NUM_VAL = 5;

	const static int PARAM_R_POS_VAL_INI = 11;
	const static int PARAM_M_POS_VAL_INI = 6;
	const static int PARAM_D_POS_VAL_INI = 4;

	ref class Parameters
	{
	public:
		Parameters();
		~Parameters();

		// Get Buffers
		unsigned char * Parameters::GetBufferR(void);
		short int * Parameters::GetBufferM(void);
		float * Parameters::GetBufferD(void);

		// Set Buffers
		void Parameters::SetBufferR(void *buffer);
		void Parameters::SetBufferM(void *buffer);
		void Parameters::SetBufferD(void *buffer);

		// Set Param At Position
		void Parameters::SetParamRAtPos(int pos, unsigned char value);
		void Parameters::SetParamMAtPos(int pos, short int value);
		void Parameters::SetParamDAtPos(int pos, float value);

		// Get Param At Position
		unsigned char Parameters::GetParamRAtPos(int pos);
		short int Parameters::GetParamMAtPos(int pos);
		float Parameters::GetParamDAtPos(int pos);

	private:
		unsigned char *bufferR;
		short int *bufferM;
		float *bufferD;

		void Parameters::InitializeArrays(void);
		
	};
}

