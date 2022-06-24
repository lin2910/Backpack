#include "backpack.h"


bool isInBackpack(int* inBackpack, const int* weight, const size_t size, const int maxWeight, int & countOperation) {
	int sumWeight = 0;
	for (size_t i = 0; i < size; i++)
		if (inBackpack[i] == 1) {
			sumWeight += weight[i];
			countOperation++;
		}
	countOperation += size + 1;
	return sumWeight <= maxWeight;
}

void backpackCheck(int* inBackpack, const int* weight, const int* value, const size_t size,
	int &record, int*& recordWeight, const int maxWeight, int& countOperation) {
	if (!isInBackpack(inBackpack, weight, size, maxWeight, countOperation))
		return;
	int sumValue = 0;
	for (size_t i = 0; i < size; i++)
		if (inBackpack[i] == 1) {
			sumValue += value[i];
	}
	if (sumValue >= record) {
		record = sumValue;
		delete[]recordWeight;
		recordWeight = copy(inBackpack, size);
	}
	countOperation += size + 1;
	return;
}

void generate(int*& inBackpack, const int* weight,
 const int* value,
	const size_t size, int& record, int*& recordWeight, const int maxWeight, size_t num, int & countOperation) {
	countOperation++;
	if (num == 0) {
		inBackpack[num] = 0;
		backpackCheck(inBackpack, weight, value, size, record, recordWeight, maxWeight, countOperation);
		inBackpack[num] = 1;
		backpackCheck(inBackpack, weight, value, size, record, recordWeight, maxWeight, countOperation);
		return;
	}
	inBackpack[num] = 0;
	generate(inBackpack, weight, value, size, record, recordWeight, maxWeight, num - 1, countOperation);
	inBackpack[num] = 1;
	generate(inBackpack, weight, value, size, record, recordWeight, maxWeight, num - 1, countOperation);
}


int* copy(const int* original, const size_t size) {
	int* copy = new int[size];
	for (size_t i = 0; i < size; i++)
		copy[i] = original[i];
	return copy;
}