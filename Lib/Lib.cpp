// Lib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "utility.h"
#include "sorting.h"

void print(const int* arr, const int size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void Sorting::bubbleSort(int* arr, const int size)
{
	bool sorted = false;
	for (size_t i = 0; i < size; ++i)
	{
		sorted = false;
		for (size_t j = 0; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				sorted = true;
			}
		}
		if (!sorted)
		{
			break;
		}
	}
}

void Sorting::insertionSort(int* arr, const int size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			while (arr[j] < arr[j - 1])
			{
				std::swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void Sorting::merge(int* arr, const int p, const int q, const int r) {
	const int n1 = q - p + 1;
	const int n2 = r - q;

	int* left = new int[n1];
	int* right = new int[n2];

	for (int i = 0; i < n1; i++)
		left[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		right[j] = arr[q + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void Sorting::mergeSort(int* arr, const int start, const int end)
{
	if (start >= end) return;
	int half = start + (end - start) / 2;
	mergeSort(arr, start, half);
	mergeSort(arr, half + 1, end);
	merge(arr, start, half, end);
}

int Sorting::partition(int* arr, const int start, const int end)
{
	int pivot = arr[start];
	int i = start;
	int j = end;
	while (i < j)
	{
		do { i++; } while (arr[i] <= pivot);
		do { j--; } while (arr[j] > pivot);
		if (i < j)
		{
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[start], arr[j]);
	return j;
}

void Sorting::quickSort(int* arr, const int start, const int end)
{
	if (start >= end) return;
	int j = partition(arr, start, end);
	quickSort(arr, start, j);
	quickSort(arr, j + 1, end);
}

bool Sorting::checkAllSorts(int* arr, int* original, const int size)
{
	bubbleSort(arr, size);
	if (!isSorted(arr, size)) return false;

	std::copy(original, original + size, arr);
	insertionSort(arr, size);
	if (!isSorted(arr, size)) return false;

	std::copy(original, original + size, arr);
	mergeSort(arr, 0, size - 1);
	if (!isSorted(arr, size)) return false;

	std::copy(original, original + size, arr);
	quickSort(arr, 0, size);
	if (!isSorted(arr, size)) return false;

	return true;
}

int main()
{
	Sorting sort;
	std::map<std::string, Duration> durations;
	int size; cin >> size;
	int* arr = new int[size];
	int* original = new int[size];
	initialize(arr, original, size);

	if (isSorted(arr, size))
	{
		std::cout << "Array is already sorted\n";
		return 0;
	}
	auto start = std::chrono::steady_clock::now();
	sort.bubbleSort(arr, size);
	auto end = std::chrono::steady_clock::now();
	durations.insert(std::map<std::string, Duration>::value_type("bubbleSort", getDuration(start, end)));
	//std::cout << "bubbleSort: ";
	//print(arr, size);

	std::copy(original, original + size, arr);
	start = std::chrono::steady_clock::now();
	end = std::chrono::steady_clock::now();
	durations.insert(std::map<std::string, Duration>::value_type("insertionSort", getDuration(start, end)));
	sort.insertionSort(arr, size);
	//cout << "insertionSort: ";
	//print(arr, size);

	std::copy(original, original + size, arr);
	start = std::chrono::steady_clock::now();
	sort.mergeSort(arr, 0, size - 1);
	end = std::chrono::steady_clock::now();
	durations.insert(std::map<std::string, Duration>::value_type("mergeSort", getDuration(start, end)));
	//cout << "mergeSort: ";
	//print(arr, size);

	std::copy(original, original + size, arr);
	start = std::chrono::steady_clock::now();
	sort.quickSort(arr, 0, size);
	end = std::chrono::steady_clock::now();
	durations.insert(std::map<std::string, Duration>::value_type("quickSort", getDuration(start, end)));
	//cout << "quickSort: ";
	//print(arr, size);

	printMinDuration(durations);
	return 0;
}
