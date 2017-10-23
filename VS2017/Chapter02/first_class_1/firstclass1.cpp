// firstclass1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* first_class_1.cpp */
#include <functional>
#include <iostream>

using namespace std;

// 두 개의 int 타입 변수를 받아서 
// int 타입을 반환하는 FuncType이란 이름의 
// 함수 타입을 정의한다.
typedef function<int(int, int)> FuncType;

int addition(int x, int y)
{
	return x + y;
}

int subtraction(int x, int y)
{
	return x - y;
}

int multiplication(int x, int y)
{
	return x * y;
}

int division(int x, int y)
{
	return x / y;
}

void PassingFunc(FuncType fn, int x, int y)
{
	cout << "Result = " << fn(x, y) << endl;
}

auto main() -> int
{
	cout << "[first_class_1.cpp]" << endl;
	int i, a, b;
	FuncType func;

	// 메뉴를 출력한다.
	cout << "Select mode:" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "Choice: ";
	cin >> i;

	// 허용된 메뉴만 사용할 수 있게 한다..
	if (i < 1 || i > 4)
	{
		cout << "Please select available mode!";
		return 1;
	}
	// 변수 a의 값을 입력받는다.
	cout << "a -> ";
	cin >> a;
	
	// a의 값이 유효한지 확인한다.
	while (cin.fail())
	{
		// cin의 에러 플래그를 초기화해서 cin을 사용 가능한 상태로 만든다.
		cin.clear();
		// 마지막 입력은 무시한다.
		cin.ignore(INT_MAX, '\n');
		cout << "You can only enter numbers.\n";
		cout << "Enter a number for variable a -> ";
		cin >> a;
	}
	
	// 변수 b의 값을 입력받는다.
	cout << "b -> ";
	cin >> b;
	
	// b의 값이 유효한지 확인한다.
	while (cin.fail())
	{
		// cin의 에러 플래그를 초기화해서 cin을 사용 가능한 상태로 만든다.
		cin.clear();
		// 마지막 입력은 무시한다.
		cin.ignore(INT_MAX, '\n');
		cout << "You can only enter numbers.\n";
		cout << "Enter a number for variable b -> ";
		cin >> b;
	}
	switch (i)
	{
		case 1: PassingFunc(addition, a, b); break;
		case 2: PassingFunc(subtraction, a, b); break;
		case 3: PassingFunc(multiplication, a, b); break;
		case 4: PassingFunc(division, a, b); break;
	}
	
	return 0;
}
