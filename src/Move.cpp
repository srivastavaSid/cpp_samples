#include <iostream>
#include <vector>

class Test {
public:
    Test()
    {
        std::cout << "Test Constructor" << std::endl;
    }

    Test(const Test& )
    {
        std::cout << "Test Copy Constructor" << std::endl;
    }

    Test(Test&& ) noexcept
    {
        std::cout << "Test Move Constructor" << std::endl;
    }

    Test& operator=(Test&& ) {
        std::cout << "Test Move Assignment operator" << std::endl;
        return *this;
    }
};

class Tester {
    Test a;
public:
    Tester() {
        std::cout << "Tester Constructor" << std::endl;
    }

    Tester(Tester&& td) noexcept
        : a(std::move(td.a))
    {
        std::cout << "Tester Move Constructor" << std::endl;
    }

    Tester& operator= (Tester&& td) {
        std::cout << "Tester Move Assignment operator" << std::endl;
        /* swap creates a temp object using move constructor then:
                1) call move assignment operator between parameters
                2) call move assignment operator between temp and empty parameter

            thus swap should not be used in move constructor and move aggignment operator directly:
                std::swap(*this, td);
            But can be used with memberiwse swapping with caution.
        */
        std::swap(a, td.a);
        return *this;
    }
};

void main() {
    std::vector<Test> testVec;
    //testVec.reserve(3);
    std::cout << "First Item" << std::endl;
    testVec.push_back(Test());
    std::cout << "Second Item" << std::endl;
    Test t;
    testVec.push_back(t);
    std::cout << "Third Item" << std::endl;
    testVec.emplace_back();
    std::cout << "\nEnd of move constructor test\n\n";

    Tester x;
    Tester y;
    std::cout << "\nchecking move assignment\n\n";
    y = std::move(x);
}