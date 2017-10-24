/* filter_1.cpp */
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[filter_1.cpp]" << endl;

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

	// int를 원소로 가지는 벡터 primes를 선언한다.
	vector<int> primes;

	// 벡터 numbers에서 소수(prime number)만 필터링해서
	// 벡터 primes에 추가한다.
	copy_if(
		begin(numbers),
		end(numbers),
		back_inserter(primes),
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

	// 벡터 primes를 출력한다.
	cout << "The primes numbers: " << endl;
	copy(
		begin(primes),
		end(primes),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
