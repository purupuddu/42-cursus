#pragma once
#include "Data.hpp"
#include <stdint.h>

class Serializer{
private:
    Serializer();
public:
    static uintptr_t serialize(Data *data);
    static Data* deserialize(uintptr_t ptr);
};
