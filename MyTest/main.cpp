#include <iostream>
#include "../include/bookstore/bookstore.h"

int main()
{
    for (int iter = 1; iter <= 1; iter++)
    {
        const double x = 30;
        const int &ref = x;
        std::cout << ref << std::endl;
        std::cout << &ref << std::endl;
        std::cout << &x << std::endl;
        // ref = x;
    }
    // test();
    // system("pause");
    return 0;
}
