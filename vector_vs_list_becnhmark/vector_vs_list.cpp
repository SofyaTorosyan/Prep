#include <iostream>
#include <vector>
#include <list>
#include <windows.h>
#include <fstream>
#include "psapi.h"
using namespace std;


unsigned long long getUsedMemory()
{
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	SIZE_T memUsed = pmc.WorkingSetSize;
	return memUsed;
}


template <typename T>
void fill_vector(std::vector<T>& vec) {
	std::ofstream vec_csv("vec.csv");
	for (int i = 0; i < 1000; i++) {
		vec.push_back(T{});
		vec_csv << i << ',' << getUsedMemory() << std::endl;
	}
	vec_csv.close();
}

template <typename T>
void fill_list(std::list<T>& list) {
	std::ofstream list_csv("list.csv");
	for (int i = 0; i < 10000; i++) {
		list.push_back(T{});
		list_csv << i << ',' << getUsedMemory() << std::endl;
	}
	list_csv.close();
}

int main()
{
	std::vector<int> my_vec;
	std::list<int> my_list;
	fill_vector(my_vec);
	//std::cout << getUsedMemory() << std::endl;
	fill_list(my_list);
	//std::cout << getUsedMemory() << std::endl;
	std::cout << "done\n";
	return 0;
}