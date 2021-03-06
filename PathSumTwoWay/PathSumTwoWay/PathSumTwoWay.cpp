// PathSumTwoWay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Search.h"
#include <iostream>
#include <chrono>
int main()
{

	auto s = new Search();
	auto start = std::chrono::steady_clock::now();
	for (size_t i = 0; i <= 1000; i++)
	{
		s->start();
	}
	std::cout << std::chrono::duration <double, std::milli>(std::chrono::steady_clock::now() - start).count() << "ms for 1000 tries, path value: " << s->start();
	getchar();
}

