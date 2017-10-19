/* lambda_tiny_func.cpp */
#include <vector>
#include <algorithm>
#include <iostream>
#include "../vehicle/vehicle.h"

using namespace std;

auto main() -> int
{
	cout << "[lambda_tiny_func.cpp]" << endl;

	// 여러 개의 Vehicle 인스턴스를 생성하고 초기화한다.
	Vehicle car("car", 4);
	Vehicle motorcycle("motorcycle", 2);
	Vehicle bicycle("bicycle", 2);
	Vehicle bus("bus", 6);

	// 위에서 만들어 둔 Vehicle 인스턴스를 벡터에 추가한다.
	vector<Vehicle> vehicles = { car, motorcycle, bicycle, bus };

	// 람다 표현식으로 벡터의 각 원소를 출력한다.
	cout << "All vehicles:" << endl;
	for_each(
		begin(vehicles),
		end(vehicles),
		[](const Vehicle &vehicle) {
		cout << vehicle.GetType() << endl;
	});

	return 0;
}

