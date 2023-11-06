#include "pch.h"
#include "utility.h"
#include <algorithm>

void initialize(int* arr, int* original, int& size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = std::rand() % 100;
	}
	std::copy(arr, arr + size, original);
}

bool isSorted(const int* arr, const int size)
{
	if (size == 0 || size == 1)
	{
		return 1;
	}
	for (int i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
			return false;
	}
	return true;
}