#pragma once
#include <cstdlib>


template <typename T>
void iter(T * array, const size_t len, void (*f)(T &x))
{
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

template <typename T>
void iter(const T * array, const size_t len, void (*f)(const T &x))
{
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
}