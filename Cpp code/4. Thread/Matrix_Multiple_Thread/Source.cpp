#include <iostream>
#include <thread>
#include <random>

using namespace std;

#define MAT_SIZE 1000000
#define ROW_SIZE 1000
#define TRACK true

void calc(int* Result_ptr, int* M1_row_ptr, int* M2_T, int start, int end)
{
	for (int M1_r = start; M1_r < end; M1_r++)
	{
		if (TRACK) cout << "Calculating row: " << M1_r << endl;
		int* M2_col_ptr = M2_T;
		for (int M2_c = 0; M2_c < ROW_SIZE; M2_c++)
		{
			int result = 0;
			for (int i = 0; i < ROW_SIZE; i++)
			{
				result += M1_row_ptr[i] * M2_col_ptr[i];
			}
			*Result_ptr++ = result;
			M2_col_ptr += ROW_SIZE;
		}
		M1_row_ptr += ROW_SIZE;
	}
}

int main()
{
	int* M1 = new int[MAT_SIZE];
	int* M2_T = new int[MAT_SIZE];
	int* M_result_sequence = new int[MAT_SIZE];
	int* M_result_thread = new int[MAT_SIZE];

	// INIT
	srand(0);
	int* M1_ptr = M1;
	int* M2_ptr = M2_T;
	for (int i = 0; i < MAT_SIZE; i++)
	{
		*M1_ptr++ = rand() % 1000;
		*M2_ptr++ = rand() % 1000;
	}

	// Sequence calculation
	int* M1_row_ptr = M1;
	int* M2_col_ptr = M2_T;
	int* Result_ptr = M_result_sequence;

	int start = clock();
	for (int M1_r = 0; M1_r < ROW_SIZE; M1_r++)
	{
		if (TRACK) cout << "Calculating row: " << M1_r << endl;
		M2_col_ptr = M2_T;
		for (int M2_c = 0; M2_c < ROW_SIZE; M2_c++)
		{
			int result = 0;
			for (int i = 0; i < ROW_SIZE; i++)
			{
				result += M1_row_ptr[i] * M2_col_ptr[i];
			}
			*Result_ptr++ = result;
			M2_col_ptr += ROW_SIZE;
		}
		M1_row_ptr += ROW_SIZE;
	}
	int end = clock();

	cout << "-------------------------------";

	// THREAD calculation
	M1_row_ptr = M1;
	M2_col_ptr = M2_T;
	Result_ptr = M_result_thread;

	int start_thread = clock();
	thread t1(calc, Result_ptr + MAT_SIZE / 4 * 0, M1 + MAT_SIZE / 4 * 0, M2_T, ROW_SIZE / 4 * 0, ROW_SIZE / 4 * 1);
	thread t2(calc, Result_ptr + MAT_SIZE / 4 * 1, M1 + MAT_SIZE / 4 * 1, M2_T, ROW_SIZE / 4 * 1, ROW_SIZE / 4 * 2);
	thread t3(calc, Result_ptr + MAT_SIZE / 4 * 2, M1 + MAT_SIZE / 4 * 2, M2_T, ROW_SIZE / 4 * 2, ROW_SIZE / 4 * 3);
	thread t4(calc, Result_ptr + MAT_SIZE / 4 * 3, M1 + MAT_SIZE / 4 * 3, M2_T, ROW_SIZE / 4 * 3, ROW_SIZE / 4 * 4);
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	int end_thread = clock();

	// Output
	cout << "Sequence time: " << end - start << endl;
	cout << "Thread timne: " << end_thread - start_thread;

	return 0;
}