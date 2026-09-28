#include "Array.hpp"



int main( void )
{
    std::cout << "**** TEST AVEC INT ****" << std::endl;
    Array<int> a(4);

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    Array<int> b(a); //Copy constructor 
    Array<int> c = b; //Overload operator= 

    std::cout << "Size of Array c : " << c.size() << " and value in the array : ";
    c.printArray();


    try
    {
        c[4] = 5;
    }
    catch (std::exception& e)
        std::cout << e.what() << std::endl;
    
    
    
    std::cout << std::endl;
    std::cout << "**** TEST AVEC STRING ****" << std::endl;
    Array<std::string> d(4);

    d[0] = "Le";
    d[1] = "test";
    d[2] = "va";
    d[3] = "marcher";

    Array<std::string> e(d); //Copy constructor 
    Array<std::string> f = e; //Overload operator= 

    std::cout << "Size of Array f : " << c.size() << " and values in the array : ";
    c.printArray();



}