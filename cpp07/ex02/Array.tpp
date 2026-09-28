#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>
#include <cstddef>


template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T> 
Array<T>::Array(const Array<T> & copy) : _array(new T[copy.size()]), _size(copy.size())
{
    for(unsigned int i(0) ; i < _size ; i++)
        this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>& Array<T>::operator = (const Array& other)
{
    if (this == &other)
        return *this;
    _array= new T[other._size];
    _size = other.size();
    for (unsigned int i(0); i < _size ; i++)
        this->_array[i] = other._array[i];
    return (*this);
}

template <typename T>
Array<T>::~Array (void)
{
    delete[] _array;
}

template <typename T>
unsigned int Array<T>::size( void ) const 
{
    return (_size);
}

template <typename T>
T& Array<T>::operator[] (unsigned int index)// Allow to use the Array<T> like if it was a type variable and as a frame so.
{
    if(index >= _size)
        throw IndexOutOfBounds();
    return(_array[index]);
}

template <typename T>
const T& Array<T>::operator[] (unsigned int index) const // Same but const 
{
    if(index >= _size)
        throw IndexOutOfBounds();
    return(_array[index]);
}

template <typename T>
void Array<T>::printArray( void ) const 
{
    for (unsigned int i(0); i < _size ; i++)
        std::cout << this->_array[i] << " " ;
    std::cout <<std::endl;
}


#endif 