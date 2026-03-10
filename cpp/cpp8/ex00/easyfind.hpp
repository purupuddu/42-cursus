#pragma once
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cont, int val)
{
    return std::find(cont.begin(), cont.end(), val);
}
