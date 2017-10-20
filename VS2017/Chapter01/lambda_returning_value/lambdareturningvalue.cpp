// lambdareturningvalue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* lambda_returning_value.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_returning_value.cpp]" << endl;

	// 벡터 vect에 정수 추가
	vector<int> vect;
	for (int i = 0; i < 10; ++i)
		vect.push_back(i);

	// 벡터 vect 내의 각 원소 출력
	cout << "Original Data:" << endl;
	for_each(
		begin(vect),
		end(vect),
		[](int n) {
		cout << n << " ";
	});
	cout << endl;

	// 또 다른 벡터 vect2 생성
	vector<int> vect2;

	// vect와 똑같은 크기로 vect2의 크기 조정
	vect2.resize(vect.size());

	// vect의 각 원소를 제곱하여 vect2에 저장
	transform(
		begin(vect),
		end(vect),
		begin(vect2),
		[](int n) {
		return n * n;
	});

	// vect2의 각 원소 출력
	cout << "Squared Data:" << endl;
	for_each(
		begin(vect2),
		end(vect2),
		[](int n) {
		cout << n << " ";
	});
	cout << endl;

	// 또 다른 벡터 vect3 생성
	vector<double> vect3;

	// vect와 똑같은 크기로 vect3의 크기 조정
	vect3.resize(vect.size());

	// vect2의 각 원소의 평균 값을 vect3에 저장
	transform(
		begin(vect2),
		end(vect2),
		begin(vect3),
		[](int n) -> double {
		return n / 2.0;
	});

	// vect3의 각 원소를 출력
	cout << "Average Data:" << endl;
	for_each(
		begin(vect3),
		end(vect3),
		[](double d) {
		cout << d << " ";
	});
	cout << endl;

	return 0;
}

