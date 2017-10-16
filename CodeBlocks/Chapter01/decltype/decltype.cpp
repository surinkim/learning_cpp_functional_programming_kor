/* decltype.cpp */
#include <iostream>

// 템플릿 함수를 생성한다.
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j)
{
    return i + j;
}

auto main() -> int
{
    std::cout << "[decltype.cpp]" << std::endl;

    // 템플릿 함수를 호출한다.
    auto d = add<int, double>(2, 2.5);

    // 결과를 출력한다.
    std::cout << "result of 2 + 2.5: " << d << std::endl;

    return 0;
}

