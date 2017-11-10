// Step01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* Main.cpp - Step01 */
#include <iostream>
#include "Customer.h"

using namespace std;

void RegisterCustomers()
{
	int i = 0;
	bool b = false;

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

	// 벡터 registeredCustomers의 모든 원소 제거
	Customer::registeredCustomers.clear();

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

		// 생성한 Customer 객체를 벡터 registeredCustomers에 저장
		Customer::registeredCustomers.push_back(c);
	}
}

auto main() -> int
{
	cout << "[Step01]" << endl;
	cout << "--------" << endl;

	// Customer 객체를 생성하고 멤버 변수의 값을 채운 뒤,
	// registeredCustomers에 저장한다.
	RegisterCustomers();

	// Customer 객체
	Customer customer;

	// 계약이 체결된 고객의 이름을 얻고 콘솔에 출력
	cout << "List of active customer names:" << endl;
	vector<string> activeCustomerNames =
		customer.GetActiveCustomerNames();
	for (auto &name : activeCustomerNames)
	{
		cout << name << endl;
	}

	return 0;
}


