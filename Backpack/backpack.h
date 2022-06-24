#pragma once

bool isInBackpack(int* inBackpack, const int* weight, const size_t size, const int maxWeight, int & countOperation);

void backpackCheck(int* inBackpack, const int* weight, const int* value,
	const size_t size, int & record, int* &recordWeight, const int maxWeight, int& countOperation);

void generate(int* &inBackpack, const int* weight, const int* value,
	const size_t size, int & record, int* &recordWeight, const int maxWeight, size_t num, int & countOperation);

int* copy(const int* original, const size_t size);