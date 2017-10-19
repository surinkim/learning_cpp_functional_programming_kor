/* vehicle.cpp */
#include "vehicle.h"

using namespace std;

// 기본 생성자
Vehicle::Vehicle() : m_totalOfWheel(0)
{
}

// 사용자 정의 생성자
Vehicle::Vehicle(const string &type, int wheel) :
	m_vehicleType(type),
	m_totalOfWheel(wheel)
{
}

// 소멸자
Vehicle::~Vehicle()
{
}
