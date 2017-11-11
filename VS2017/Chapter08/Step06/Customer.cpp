/* Customer.cpp - Step06 */
#include <algorithm>
#include "Customer.h"

using namespace std;

vector<string> Customer::GetActiveCustomerNames(
	vector<Customer> customers)
{
	return Customer::GetActiveCustomerByFunctionField<string>(
		customers,
		make_shared<CustomerName>());
}

vector<string> Customer::GetActiveCustomerAddresses(
	vector<Customer> customer)
{
	return Customer::GetActiveCustomerByFunctionField<string>(
		customer,
		make_shared<CustomerAddress>());
}

vector<string> Customer::GetActiveCustomerPhoneNumbers(
	vector<Customer> customer)
{
	return Customer::GetActiveCustomerByFunctionField<string>(
		customer,
		make_shared<CustomerPhoneNumber>());
}

vector<string> Customer::GetActiveCustomerEmails(
	vector<Customer> customer)
{
	return Customer::GetActiveCustomerByFunctionField<string>(
		customer,
		make_shared<CustomerEmail>());
}

int Customer::CountActiveCustomers(
	vector<Customer> customer)
{
	if (customer.empty())
		return 0;
	else
	{
		// 벡터 customer의 맨 앞 원소의 isActive 값에
		// 따라 add 변수 초기화
		int add = customer.front().isActive ? 1 : 0;

		// 벡터의 첫번째 요소 제거
		customer.erase(customer.begin());

		// 재귀 실행
		return add + CountActiveCustomers(
			customer);
	}
}

template<typename T>
vector<T> Customer::GetActiveCustomerByFunctionField(
	vector<Customer> customers,
	const shared_ptr<BaseClass<Customer, T>>
	&classField)
{
	vector<Customer> activeCustomers;
	vector<T> returnList;

	copy_if(
		customers.begin(),
		customers.end(),
		back_inserter(activeCustomers),
		[](Customer customer)
	{
		if (customer.isActive)
			return true;
		else
			return false;
	});

	for_each(
		activeCustomers.begin(),
		activeCustomers.end(),
		[&returnList, &classField](Customer customer)
	{
		returnList.push_back(
			classField->InvokeFunction(
				make_shared<Customer>(customer))
		);
	});

	return returnList;
}
