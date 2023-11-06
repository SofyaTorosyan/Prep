#pragma once
#include "pch.h"
#include "framework.h"
class Sorting {
public:
	void bubbleSort(int* arr, const int size);
	void insertionSort(int* arr, const int size);
	void merge(int* arr, int p, const int q, const int r);
	void mergeSort(int* arr, const int start, const int end);
	int partition(int* arr, const int start, const int end);
	void quickSort(int* arr, const int start, const int end);
	bool checkAllSorts(int* arr, int* original, const int size);
};