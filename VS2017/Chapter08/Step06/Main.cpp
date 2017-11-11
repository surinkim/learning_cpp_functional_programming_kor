// Step06.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* Main.cpp - Step06 */
#include <iostream>
#include <functional>
#include <chrono>
#include "Customer.h"

using namespace std;

template<class T> class Memoization
{
private:
	T const & (*m_subRoutine)(Memoization *);
	mutable T m_recordedFunc;
	function<T()> m_func;

	static T const & ForceSubroutine(
		Memoization * d)
	{
		return d->DoRecording();
	}

	static T const & FetchSubroutine(
		Memoization * d)
	{
		return d->FetchRecording();
	}

	T const & FetchRecording()
	{
		return m_recordedFunc;
	}

	T const & DoRecording()
	{
		m_recordedFunc = m_func();
		m_subRoutine = &FetchSubroutine;
		return FetchRecording();
	}

public:
	Memoization(
		function<T()> func)
		: m_func(func),
		m_subRoutine(&ForceSubroutine),
		m_recordedFunc(T())
	{
	}

	T Fetch()
	{
		return m_subRoutine(this);
	}
};

vector<Customer> RegisterCustomers()
{
	int i = 0;
	bool b = false;

	vector<Customer> returnValue;

	// 고객 이름으로 nameList 초기화
	vector<string> nameList =
	{
		"William",
		"Aiden",
		"Rowan",
		"Jamie",
		"Quinn",
		"Haiden",
		"Logan",
		"Emerson",
		"Sherlyn",
		"Molly"
	};

	for (auto name : nameList)
	{
		// Customer 객체를 생성하고 
		// 각 멤버 변수 값을 채운다.
		Customer c;
		c.id = i++;
		c.name = name;
		c.address = "somewhere";
		c.phoneNumber = "0123";
		c.email = name + "@xyz.com";
		c.isActive = b;

		// NOT 비트 연산자를 사용해서 
		// false, true를 번갈아 가며 저장함.
		b = !b;

		// 생성한 Customer 객체를 벡터 returnValue에 저장
		returnValue.push_back(c);
	}

	return returnValue;
}

auto main() -> int
{
	cout << "[Step06]" << endl;
	cout << "--------" << endl;

	// 프로그램 시작 시간을 저장
	auto start = chrono::high_resolution_clock::now();

	// Customer 객체
	Customer customer;

	// 계약이 체결된 고객 수를 계산함.
	cout << "Total active customers: " << endl;
	cout << customer.CountActiveCustomers(
		RegisterCustomers());
	cout << endl << "--------" << endl;

	// 메모이제이션 인스턴스 초기화
	Memoization<vector<string>> custMemo(
		[customer]()
	{
		return customer.GetActiveCustomerNames(
			RegisterCustomers());
	});

	// 계약이 체결된 고객의 이름 목록을 구해서 콘솔에 출력
	cout << "List of active customer names:" << endl;
	vector<string> activeCustomerNames =
		custMemo.Fetch();
	for (auto name : activeCustomerNames)
	{
		cout << name << endl;
	}

	// 프로그램 종료 시간을 저장
	auto finish = chrono::high_resolution_clock::now();

	// 프로그램 실행 시간 계산
	chrono::duration<double, milli> elapsed = finish - start;

	// 프로그램 실행 시간 출력
	cout << "--------" << endl;
	cout << "Total consuming time = ";
	cout << elapsed.count() << " milliseconds" << endl;

	return 0;
}


