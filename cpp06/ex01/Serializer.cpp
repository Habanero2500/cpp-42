#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t cast = reinterpret_cast<uintptr_t>(ptr);
    return cast;
}
Data* Serializer::deserialize(uintptr_t cast_uint)
{
    Data* data = reinterpret_cast<Data*>(cast_uint);
    return data;
}

