// LargestPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include "Palindrome.h"

int main()
{
	auto palindrome = new Palindrome();
	auto start = std::chrono::steady_clock::now();
	for (size_t i = 0; i <= 1000; i++)
	{
		palindrome->findLargest();
	}
	std::cout << std::chrono::duration <double, std::milli>(std::chrono::steady_clock::now() - start).count() << "ms for 1000 tries, palindrome:"<< palindrome->findLargest();
	getchar();
}

