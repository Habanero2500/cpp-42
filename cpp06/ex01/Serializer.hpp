
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

    public : 

    static uintptr_t serialize(Data* ptr); // Unsigned int spécifiquement fait pour contenir des adresses
    static Data* deserialize(uintptr_t raw);

    private : 
    Serializer( void );
    ~Serializer( void );
    Serializer( const Serializer& copy );
    Serializer &operator =( const Serializer& copy );

};





#endif