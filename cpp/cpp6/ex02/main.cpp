#include "functions.hpp"




int main()
{
    for(int i = 0; i < 10; i++)
    {
        Base *base = generate();
        identify(base);
        delete base;
    }
}