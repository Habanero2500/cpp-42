#ifndef ITER_HPP
#define ITER_HPP

#include <iostream> 
#include <cctype>
#include <string>

template < typename T, typename F> // Type generique de array et type generique de fonction
void iter (T* array, unsigned int length, F f)
{
    for (unsigned int i(0); i < length; i++)
        f(array[i]);
}

template < typename T >  
void printNode(T *array, unsigned int length)
{
    for (unsigned int i(0) ; i < length ; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}


#endif