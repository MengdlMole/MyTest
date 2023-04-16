#include <iostream>
#include "../../include/Win/bookstore.h"

void test()
{
    int label = 0;
    while (std::cin >> label)
    {
        std::cout << "label is " << label << std::endl;
        if (label == 0)
        {
            std::cout << "exit" << std::endl;
            break;
        }
    }
}
