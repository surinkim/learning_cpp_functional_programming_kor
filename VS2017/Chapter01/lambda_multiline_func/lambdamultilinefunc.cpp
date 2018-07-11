// lambdamultilinefunc.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* lambda_multiline_func.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_multiline_func.cpp]" << endl;

	// 벡터에 정수 추가
	vector<int> vect;
	for (int i = 0; i < 10; ++i)
		vect.push_back(i);

	// 벡터 내의 원소가 소수인지 아닌지 출력
	for_each(
		begin(vect),
		end(vect),
		[](int n) {
		cout << n << " is";
		if (n < 2)
		{
			cout << " not";
		}
		else
		{
			for (int j = 2; j < n; ++j)
			{
				if (n % j == 0)
				{
					cout << " not";
					break;
				}
			}
		}
		cout << " prime number" << endl;
	});
	
	return 0;
}

