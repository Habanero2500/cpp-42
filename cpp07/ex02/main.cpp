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
    {
        std::cout << e.what() << std::endl;
    }
    
    
    std::cout << std::endl;
    std::cout << "**** TEST AVEC STRING ****" << std::endl;
    Array<std::string> d(4);

    d[0] = "Le";
    d[1] = "test";
    d[2] = "va";
    d[3] = "marcher";

    Array<std::string> e(d); //Copy constructor 
    Array<std::string> f = e; //Overload operator= 

    std::cout << "Size of Array f : " << e.size() << " and values in the array : ";
    e.printArray();
        
    try
    {
        e[4] = "test";
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }