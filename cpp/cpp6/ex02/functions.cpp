#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base * generate()
{
    static bool rand_init = false;

    if (!rand_init)
    {
        srand(time(0));
        rand_init = true;
    }
    switch(rand() % 3)
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A\n";
        (void)a;
        return;
    } catch (std::exception &e) {}

    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << "B\n";
        (void)b;
        return;
    } catch (std::exception &e) {}

    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C\n";
        (void)c;
    } catch (std::exception &e) {
        std::cout << "I can't identify it\n";
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A\n";
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B\n";
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C\n";
    }
    else std::cout << "I can't identify it\n";
}
