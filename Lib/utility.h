#pragma once
#include "pch.h"
#include "framework.h"
#include <chrono>
#include <map>
#include <string>
#include <windows.h> 
#include <iostream>
using namespace std;

void initialize(int* arr, int* original, int& size);
bool isSorted(const int* arr, const int size);

struct Duration
{
	double hour;
	double min;
	double sec;

	Duration() : hour{ 0 }, min{ 0 }, sec{ 0 }
	{ }
	Duration(double h, double m, double s) : hour{ h }, min{ m }, sec{ s }
	{ }

	bool operator< (const Duration& dur) const
	{
		return ((hour < dur.hour) ||
				(hour == dur.hour && min < dur.min) ||
				(hour == dur.hour && min < dur.min && sec < dur.sec));
	}

	bool operator== (const Duration& dur) const
	{
		return hour == dur.hour && min == dur.min && sec == dur.sec;
	}
};

Duration getDuration(const  std::chrono::time_point<std::chrono::steady_clock> start, std::chrono::time_point<std::chrono::steady_clock> end)
{
	const auto time = end - start;
	const auto hrs = std::chrono::duration_cast<std::chrono::hours>(time);
	const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time - hrs);
	const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time - hrs - mins);
	return Duration(hrs.count(), mins.count(), secs.count());
}

void printMinDuration(const std::map<std::string, Duration> durations)
{
	std::string name("");
	Duration minimum(DBL_MAX, DBL_MAX, DBL_MAX);
	for (const auto& dur : durations) 
	{
		minimum = dur.second < minimum ? dur.second : minimum;
		name = dur.first;
	}

	std::cout << name << " : " << minimum.hour << "  " << minimum.min << " " << minimum.sec << std::endl;
	std::cout << "SortingName     -->   Duration \n";
	for (const auto& dur : durations) 
	{
		const auto time = dur.second;
		if (dur.first == name)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << dur.first << " : " << time.hour << "  " << time.min << " " << time.sec << std::endl;
			SetConsoleTextAttribute(hConsole, 0);
		}
		else 
		{
			std::cout << dur.first << " : " << time.hour << "  " << time.min << " " << time.sec << std::endl;
		}
	}
}