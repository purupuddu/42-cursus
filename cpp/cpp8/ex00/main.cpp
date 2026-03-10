#include "easyfind.hpp"
#include <vector>
#include <set>
#include <iostream>
#include <cassert>

int main()
{
    std::vector<int> v(30, 10);
    v[5] = 5;

    assert (easyfind(v, 69) == v.end());
    std::cout << "69 not found" << std::endl;
    std::cout << 10 << " at position " << easyfind(v, 10) - v.begin() << std::endl;
    std::cout << 5 << " at position " << easyfind(v, 5) - v.begin() << std::endl;
    std::set<int> s;
    s.insert(5);
    s.insert(8);
    if(easyfind(s, 8) != s.end())
        std::cout << "Found 8" << std::endl;
    if(easyfind(s, 67) == s.end())
        std::cout << "No 67 in the set" << std::endl;
}
