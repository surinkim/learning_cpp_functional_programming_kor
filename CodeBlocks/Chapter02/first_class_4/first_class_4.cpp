/* first_class_4.cpp */
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>

using std::vector;
using std::function;
using std::transform;
using std::back_inserter;
using std::cout;
using std::endl;

// double 타입을 인자로 받고 double 타입을 반환하는 HyperbolicFunc란 이름의
// 함수 타입을 정의한다.
typedef function<double(double)> HyperbolicFunc;

// 4개의 함수를 가지도록 벡터를 초기화한다.
vector<HyperbolicFunc> funcs = {
	sinh,
	cosh,
	tanh,
	[](double x) {
	return x*x; }
};

// 4개의 함수를 가지도록 벡터를 초기화한다.
vector<HyperbolicFunc> inverseFuncs = {
	asinh,
	acosh,
	atanh,
	[](double x) {
	return exp(log(x) / 2); }
};

// 재사용 가능한 템플릿을 선언한다.
template <typename A, typename B, typename C>
function<C(A)> compose(
	function<C(B)> f,
	function<B(A)> g) {
	return [f, g](A x) {
		return f(g(x));
	};
}

auto main() -> int
{
	cout << "[first_class_4.cpp]" << endl;

	// HyperbolicFunc 타입을 가지는 벡터를 선언한다.
	vector<HyperbolicFunc> composedFuncs;

	// 여러개의 double 타입을 가지도록 벡터를 초기화한다.
	vector<double> nums;
	for (int i = 1; i <= 5; ++i)
		nums.push_back(i * 0.2);

	// 벡터 내의 원소들을 변환한다.
	transform(
		begin(inverseFuncs),
		end(inverseFuncs),
		begin(funcs),
		back_inserter(composedFuncs),
		compose<double, double, double>);
	for (auto num : nums)
	{
		for (auto func : composedFuncs)
			cout << "f(g(" << num << ")) = " << func(num) << endl;
		cout << "---------------" << endl;
	}

	return 0;
}
