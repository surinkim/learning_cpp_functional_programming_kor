/* not_optimize_code.cpp */
#include <iostream>
#include <functional>
#include <chrono>

using namespace std;

template<class T> class Delay
{
private:
	function<T()> m_func;
public:
	Delay(function<T()> func) : m_func(func)
	{
	}

	T Fetch()
	{
		return m_func();
	}
};

// 피보나치 수열을 계산하는 함수
int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

auto main() -> int
{
	cout << "[not_optimize_code.cpp]" << endl;

	// 프로그램 시작 시간 기록
	auto start = chrono::high_resolution_clock::now();

	// 피보나치 계산 결과를 저장할 int 변수 초기화
	int fib40Result = 0;

	// fib40 생성
	Delay<int> fib40([]()
	{
		return fibonacci(40);
	});

	for (int i = 1; i <= 5; ++i)
	{
		cout << "Invocation " << i << ". ";

		// 시작 시간 기록
		auto start = chrono::high_resolution_clock::now();

		// fib40 인스턴스의 Fetch() 함수 호출
		fib40Result = fib40.Fetch();

		// 종료 시간 기록
		auto finish = chrono::high_resolution_clock::now();

		// 실행 시간 계산
		chrono::duration<double, milli> elapsed = finish - start;

		// 결과 출력
		cout << "Result = " << fib40Result << ". ";

		// fib40.Fetch() 실행 시간 출력
		cout << "Consuming time = " << elapsed.count();
		cout << " milliseconds" << endl;
	}

	// 프로그램 종료 시간 기록
	auto finish = chrono::high_resolution_clock::now();

	// 프로그램 실행 시간 계산
	chrono::duration<double, milli> elapsed = finish - start;

	// 프로그램 실행 시간 출력
	cout << "Total consuming time = ";
	cout << elapsed.count() << " milliseconds" << endl;

	return 0;
}


