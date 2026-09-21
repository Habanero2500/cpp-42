#include "Serializer.hpp"

static uintptr_t serialize(Data* ptr)
{
    static uintptr_t cast = reinterpret_cast<uintptr_t>(ptr);
    return cast;
}
static Data* deserialize(uintptr_t cast_uint)
{
    static Data* data = reinterpret_cast<Data*>(cast_uint);
    return data;
}

