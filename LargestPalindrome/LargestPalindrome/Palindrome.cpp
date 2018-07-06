#include "stdafx.h"
#include "Palindrome.h"

#include <iostream>
#include <cmath>
// Palindrome is number which reads from left to right and from right to left same way
// ex. 901109

#define RANGE_OFFSET 5

bool Palindrome::isPalindrome(unsigned number)
{
	auto left = number / 1000;
	auto rightNumber = number % 1000;
	auto right = rightNumber % 10 * 100 + ((rightNumber / 10) % 10) * 10 + (rightNumber / 100) % 10;
	return left == right;
}

bool Palindrome::isProper(unsigned number)
{
	double square = sqrt(number);
	int first = square,
		second = square+1;
	int maxOffset = ((square - first)*number) + RANGE_OFFSET,
		offset = 0;
	bool pass = false;
	while (first > 99 && second <= 999) {
		if (maxOffset <= offset)
			return false;
		if (first*second == number)
			return true;
		if (pass) {
			--first;
			++offset;
		}
		else
			++second;
		pass = !pass;
	}
	return false;
}

int Palindrome::findLargest()
{
	for (size_t palindrome = 999999; palindrome > 100000; palindrome--)
	{
		if (isPalindrome(palindrome) && isProper(palindrome)) {
			return palindrome;
		}
	}

}

Palindrome::Palindrome()
{
}


Palindrome::~Palindrome()
{
}
