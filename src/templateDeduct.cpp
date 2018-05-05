#include <iostream>

template <typename T>
void func1 (T&& x)
{
    std::cout << typeid(x).name() << std::endl;
}

void main()
{
    int x = 10;
    const int cx = x;
    const int& rx = x;
    func1(x);
    func1(cx);
    func1(rx);
}