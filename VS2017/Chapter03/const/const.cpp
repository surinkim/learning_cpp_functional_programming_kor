// const.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* const.cpp */
#include <iostream>

using namespace std;

// const 멤버 age를 가지는 MyAge 클래스 구현
class MyAge
{
public:
	const int age;
	MyAge(const int initAge = 20) :
		age(initAge)
	{
	}
};

auto main() -> int
{
	cout << "[const.cpp]" << endl;

	// 두 개의 MyAge 클래스 인스턴스 선언
	MyAge AgeNow, AgeLater(8);

	// AgeNow의 age 값 출력
	cout << "My current age is ";
	cout << AgeNow.age << endl;

	// AgeLater의 age 값 출력
	cout << "My age in eight years later is ";
	cout << AgeLater.age << endl;

	return 0;
}

