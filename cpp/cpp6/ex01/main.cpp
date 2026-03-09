#include "Serializer.hpp"
#include <cassert>
#include <iostream>

int main()
{
    Data dt;
    dt.n = 42;
    dt.s1 = "ciao";
    dt.s2 = "ciaone";

    uintptr_t raw;
    raw = Serializer::serialize(&dt);
    Data *ptr = Serializer::deserialize(raw);

    assert(&dt == ptr);
    std::cout << "Assertion passed\n"; 

}