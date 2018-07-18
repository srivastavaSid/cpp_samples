#include <iostream>

void clear(int* x) {
    std::cout << *x << std::endl;
    delete x;
    x = nullptr;
}

void main()
{
    int *tmp = new int(10);
    std::cout << "tmp = " << tmp << " insideTemp = " << *tmp << std::endl;
    clear(tmp);
    std::cout << "tmp = " << tmp << " insideTemp = " << *tmp << std::endl;
}