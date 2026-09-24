#include "iter.hpp"


void addone(int &value)
{
    value++;
}
void twotimes(double &value)
{
    value*=2;
}

void maj( std::string &word )
{
    for (unsigned int i(0); i < word.length(); i++)
        word[i] = toupper(word[i]);
}

int main ( void )
{
    int a[5] = {1, 2, 3, 4, 5};
    
    std::cout << "**** TEST WITH AN INT ARRAY ( ADD 1 ) ****" << std::endl;
    std:: cout << "Before : ";
    printNode(a, 5);
    iter(a, 5, addone);
    std:: cout << "After : ";
    printNode(a, 5); 
    
    ///////////////////////////////////////////////////////////////////////////////////
    
    std::cout << std::endl << "**** TEST WITH A DOUBLE ARRAY ( X2 ) ****" << std::endl;
    double b[5] = {1.5, 2.3, 3.4, 4.5, 5.158};
    printNode(b, 5);
    iter(b, 5, twotimes);
    printNode(b, 5);

    ///////////////////////////////////////////////////////////////////////////////////
    
    std::cout << std::endl << "**** TEST WITH A DOUBLE ARRAY ( X2 ) ****" << std::endl;
    std::string c[6] = {"test", "to", "know", "if", "it's" " workin"};
    printNode(c, 6);
    iter(c, 6, maj);
    printNode(c, 6);
    
    return 0 ;
}