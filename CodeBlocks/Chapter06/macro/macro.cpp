/* macro.cpp */
#include <iostream>

using namespace std;

// Defining macro
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

auto main() -> int
{
	cout << "[macro.cpp]" << endl;

	// 두 개의 int 변수 초기화
	int x = 10;
	int y = 20;

	// 매크로 MAX를 사용하고 그 결과를 z에 대입
	int z = MAX(x, y);

	// 결과 출력
	cout << "Max number of " << x << " and " << y;
	cout << " is " << z << endl;

	return 0;
}
