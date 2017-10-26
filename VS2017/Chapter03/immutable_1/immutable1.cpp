// immutable1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* immutable_1.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[immutable_1.cpp]" << endl;

	// int 변수 초기화
	int mutableVar = 100;
	cout << "Initial mutableVar = " << mutableVar;
	cout << endl;

	// mutableVar0 - 9 변수들을 불변 객체로 다룬다.
	int mutableVar0 = mutableVar + 0;
	int mutableVar1 = mutableVar0 + 1;
	int mutableVar2 = mutableVar1 + 2;
	int mutableVar3 = mutableVar2 + 3;
	int mutableVar4 = mutableVar3 + 4;
	int mutableVar5 = mutableVar4 + 5;
	int mutableVar6 = mutableVar5 + 6;
	int mutableVar7 = mutableVar6 + 7;
	int mutableVar8 = mutableVar7 + 8;
	int mutableVar9 = mutableVar8 + 9;
	int mutableVar10 = mutableVar9 + 10;

	// mutableVar10 출력
	// mutalbeVar10은 초기화 이후, 수정되지 않았으므로, 불변 객체다.
	cout << "After manipulating mutableVar = " << mutableVar10;
	cout << endl;
	
	return 0;
}

