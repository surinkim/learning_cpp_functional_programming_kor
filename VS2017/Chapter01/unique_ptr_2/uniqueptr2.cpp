// uniqueptr2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* unique_ptr_2.cpp */
#include <memory>
#include <iostream>

using namespace std;

struct BodyMass
{
	int Id;
	float Weight;

	BodyMass(int id, float weight) :
		Id(id),
		Weight(weight)
	{
		cout << "BodyMass is constructed!" << endl;
		cout << "Id = " << Id << endl;
		cout << "Weight = " << Weight << endl;
	}

	BodyMass(const BodyMass &other) :
		Id(other.Id),
		Weight(other.Weight)
	{
		cout << "BodyMass is copy constructed!" << endl;
		cout << "Id = " << Id << endl;
		cout << "Weight = " << Weight << endl;
	}

	~BodyMass()
	{
		cout << "BodyMass is destructed!" << endl;
	}
};
auto main() -> int
{
	cout << "[unique_ptr_2.cpp]" << endl;
	
	auto myWeight = make_unique<BodyMass>(1, 165.3f);
	
	// unique_ptr를 사용했기 때문에
	// 컴파일러는 동일한 메모리나 객체를 가리키는 또 다른 포인터 생성을
	// 금지한다.
	//auto myWeight2 = myWeight;
	
	// *myWeight는 unique_ptr이 아닌, 할당된 실제 객체를 나타내므로
	// 아래 코드는 허용된다.
	auto copyWeight = *myWeight;

	return 0;
}

