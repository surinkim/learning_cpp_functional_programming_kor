// macroswap.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* macroswap.cpp */
#include <iostream>

using namespace std;

// 여러 줄로 이루어진 SWAP 매크로 정의
#define SWAP(a,b) { \
	 (a) ^= (b); \
	 (b) ^= (a); \
	 (a) ^= (b); \
 }

auto main() -> int
{
	cout << "[macroswap.cpp]" << endl;

	// 두 개의 int 변수 초기화
	int x = 10;
	int y = 20;

	// 교환 전 변수 값 출력
	cout << "before swapping" << endl;
	cout << "x = " << x << ", y = " << y;
	cout << endl << endl;

	// SWAP 매크로 사용
	SWAP(x, y);

	// 교환 후 변수 값 출력
	cout << "after swapping" << endl;
	cout << "x = " << x << ", y = " << y;
	cout << endl;

	return 0;
}
