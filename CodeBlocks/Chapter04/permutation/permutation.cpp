/* permutation.cpp */
#include <iostream>

using namespace std;

// 인수로 전달받은 string의 순열을 계산한다.
void doPermute(
	const string &chosen,
	const string &remaining)
{
	if (remaining == "")
	{
		cout << chosen << endl;
	}
	else
	{
		for (uint32_t u = 0; u < remaining.length(); ++u)
		{
			doPermute(
				chosen + remaining[u],
				remaining.substr(0, u)
				+ remaining.substr(u + 1));
		}
	}
}

// doPermute() 호출
void permute(
	const string &s)
{
	doPermute("", s);
}

auto main() -> int
{
	cout << "[permutation.cpp]" << endl;

	// str 변수를 선언하고
	// 변수에 채울 문자열을 입력받는다.
	string str;
	cout << "Permutation of a string" << endl;
	cout << "Enter a string: ";
	getline(cin, str);

	// permute() 함수를 호출해서 가능한 순열을 찾는다.
	cout << endl << "The possibility permutation of ";
	cout << str << endl;
	permute(str);

	return 0;
}
