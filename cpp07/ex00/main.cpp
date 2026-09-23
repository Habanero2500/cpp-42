#include "Whatever.hpp"
#include <iostream>


void present(std::string str)
{
    std::cout << "****" << str << "****" << std::endl;
}

int main ( void )
{
    int a(10);
    int b(5);
    present("TEST WITH INT");
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
    std::cout << "Min between A and B = " << min(a, b) << std::endl;
    std::cout << "Max between A and B = " << max(a, b) << std::endl;
    swap(a, b);     
    std::cout << "After swap A = " << a << std::endl;
    std::cout << "After swap B = " << b << std::endl;

    present("TEST WITH FLOAT");
    float c(10.5f);
    float d(2.15f);
    std::cout << "C = " << c << std::endl;
    std::cout << "D = " << d << std::endl;
    std::cout << "Min between C and D = " << min(c, d) << std::endl;
    std::cout << "Max between C and D = " << max(c, d) << std::endl;
    swap(c, d);     
    std::cout << "After swap C = " << c << std::endl;
    std::cout << "After swap D = " << d << std::endl;

    return 0;
}