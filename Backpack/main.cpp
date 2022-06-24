#include <string>
#include <iostream>

#include "work_with_file.h"
#include "backpack.h"
#include "crtdynmem.h"

using namespace std;

int main(int argc, const char * argv[]) {
	if (argc == 7) {
		try {
			const char* InputFile_c = argv[1];
			const char* InputFile_w = argv[2];
			const char* InputFile_p = argv[3];
			const char* OutputFile_r = argv[4];
			const char* OutputFile_s = argv[5];
			const char* OutputFile_t = argv[6];
			int maxWeight = get_number(InputFile_c);

			size_t size;
			int* weight;// = new int[100];
			weight = get_array(InputFile_w);
			int* value;// = new int[100];
			value = get_array(InputFile_p, size);

			int* inBackpack = new int[size];
			for (size_t i = 0; i < size; i++)
				inBackpack[i] = 0;
			int record = 0;
			int* recordWeight = new int[size];
			for (size_t i = 0; i < size; i++)
				recordWeight[i] = 0;

			int countOperation = 0;

			//начало отсчета времени
			clock_t start = clock();

			generate(inBackpack, weight, value, size, record, recordWeight, maxWeight, size-1, countOperation);
			// конец отсчета времени
			clock_t stop = clock();

			// количество секунд
			double seconds = double(stop - start) / CLOCKS_PER_SEC;

			put_number(OutputFile_s, record);
			put_array(OutputFile_r, recordWeight, size);
			put_number(OutputFile_t, seconds, countOperation);
			
			delete[]inBackpack;
			delete[]recordWeight;
			delete[]weight;
			delete[]value;
		}
		catch (const std::exception& e) {
			cout << "Exeption: " << e.what() << endl;
		}
		//system("pause");
		return 0;
	}
	cout << "Invalid count of arguments" << endl;
	/*
	
	const char* InputFile_c = "p01_c.txt";
	const char* InputFile_w = "p01_w.txt";
	const char* InputFile_p = "p01_p.txt";
	const char* OutputFile_s = "r01_s.txt";
	const char* OutputFile_r = "r01_r.txt";
	const char* OutputFile_t = "r01_t.txt";

	try	{
		int maxWeight = get_number(InputFile_c);

		size_t size;
		int* weight;// = new int[100];
		weight = get_array(InputFile_w);
		int* value;// = new int[100];
		value = get_array(InputFile_p, size);

		cout << "weight : " << endl;
		for (size_t i = 0; i < size; i++)
			cout << weight[i] << ' ';

		cout << endl << "value : "  << endl;
		for (size_t i = 0; i < size; i++)
			cout << value[i] << ' ';
		cout << endl;

		
		int* recordWeight = new int[size];
		for (size_t i = 0; i < size; i++)
			recordWeight[i] = 0;

		int countOperation = 0;

		int record = 0;

		int* inBackpack = new int[size];
		for (size_t i = 0; i < size; i++)
			inBackpack[i] = 0;

		//начало отсчета времени
		clock_t start = clock();

		generate(inBackpack, weight, value, size, record, recordWeight, maxWeight, size-1, countOperation);
		// конец отсчета времени
		clock_t stop = clock();

		// количество секунд
		double seconds = double(stop - start) / CLOCKS_PER_SEC;

		cout << "time : " << seconds << endl;

		cout << "countOperation : " << countOperation << endl;

		cout << "What in bag : "  << endl;
		for (size_t i = 0; i < size; i++)
			cout << recordWeight[i];// << endl;
		cout << endl;
		cout << "size : " << size << endl;


		cout << "put_number " << endl;

		put_number(OutputFile_s, record);
		cout << "put_array " << endl;

		put_array(OutputFile_r, recordWeight, size);
		cout << "put_number " << endl;

		put_number(OutputFile_t, seconds, countOperation);


		cout << endl << "inBackpack : " << endl;
		for (size_t i = 0; i < size; i++)
			cout << inBackpack[i] << ' ';
		cout << endl;

		
		//cout << "delete inBackpack" << endl;
		//delete[]inBackpack;

		cout << "delete recordWeight" << endl;
		delete[]recordWeight;

		cout << "delete weight" << endl;
		delete[]weight;

		cout << "delete value" << endl;
		delete[]value;
	}
	catch (const std::exception& e) {
		cout << "Exeption: " << e.what() << endl;
	}
	cout << "end" << endl;

	_CrtDumpMemoryLeaks();
	*/

	system("pause");
	return 0;
}
