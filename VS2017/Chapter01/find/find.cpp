// find.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* find.cpp */
#include <vector>
#include <algorithm>
#include <iostream>
#include "../vehicle/vehicle.h"

using namespace std;
bool TwoWheeled(const Vehicle &vehicle)
{
	return vehicle.GetNumOfWheel() == 2 ?
		true : false;
}

auto main() -> int
{
	cout << "[find.cpp]" << endl;

	// 여러 개의 Vehicle 인스턴스를 생성하고 초기화한다.
	Vehicle car("car", 4);
	Vehicle motorcycle("motorcycle", 2);
	Vehicle bicycle("bicycle", 2);
	Vehicle bus("bus", 6);

	// 위에서 만들어 둔 Vehicle 인스턴스를 벡터에 추가한다.
	vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

	// 벡터의 각 원소를 출력한다.
	cout << "All vehicles:" << endl;;
	for (auto v : vehicles)
		std::cout << v.GetType() << endl;
	cout << endl;

	// m_totalOfWheel이 2로 설정된 원소를 찾아서 출력한다.
	cout << "Two-wheeled vehicle(s):" << endl;
	auto tw = find_if(
		begin(vehicles),
		end(vehicles),
		TwoWheeled);
	while (tw != end(vehicles))
	{
		cout << tw->GetType() << endl;
		tw = find_if(++tw, end(vehicles), TwoWheeled);
	}
	cout << endl;

	// m_totalOfWheel이 2가 아닌 원소를 찾아서 출력한다.
	cout << "Not the two-wheeled vehicle(s):" << endl;
	auto ntw = find_if_not(begin(vehicles),
		end(vehicles),
		TwoWheeled);
	while (ntw != end(vehicles))
	{
		cout << ntw->GetType() << endl;
		ntw = find_if_not(++ntw, end(vehicles), TwoWheeled);
	}

	return 0;
}
