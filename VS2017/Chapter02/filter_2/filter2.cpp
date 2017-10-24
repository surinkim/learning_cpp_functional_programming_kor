// filter2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* filter_2.cpp */
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	cout << "[filter_2.cpp]" << endl;

	// 몇 개의 정수를 벡터에 추가한다.
	vector<int> numbers;
	for (int i = 0; i < 20; ++i)
		numbers.push_back(i);

	// 벡터 numbers를 출력한다.
	cout << "The original numbers: " << endl;
	copy(
		begin(numbers),
		end(numbers),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	// int를 원소로 가지는 벡터 nonPrimes를 선언한다.
	vector<int> nonPrimes;

	// 벡터 numbers에서 
	// 소수(prime number)는 제외하고 
	// 소수가 아닌 원소만 가져오도록 필터링해서 
	// 벡터 nonPrimes에 추가한다.
	remove_copy_if(
		numbers.begin(),
		numbers.end(),
		back_inserter(nonPrimes),
		[](int n) {
		if (n < 2) {
			return (n != 0) ? true : false;
		}
		else {
			for (int j = 2; j < n; ++j) {
				if (n % j == 0) {
					return false;
				}
			}
			return true;
		}});

	// 벡터 nonPrimes를 출력한다.
	cout << "The non-primes numbers: " << endl;
	copy(
		begin(nonPrimes),
		end(nonPrimes),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}


