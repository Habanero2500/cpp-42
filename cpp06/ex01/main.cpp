#include "Data.hpp"
#include "Serializer.hpp"

int main ()
{
    Data test;

    Data *ptr = &test;
    uintptr_t cast_to_uint = Serializer::serialize(ptr);
    std::cout << "Cast en uint :" << cast_to_uint << std::endl; 

    Data *cast_to_data = Serializer::deserialize(cast_to_uint);
    std::cout << "Adress of the data pointer : " << ptr << std::endl;
    std::cout << "Adress after the two casts : " << cast_to_data << std::endl;

    return 0;
}

