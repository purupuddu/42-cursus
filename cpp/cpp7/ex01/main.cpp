#include "iter.hpp"
#include <iostream>
#include <cstdio>

template <typename T>
void print(T &x)
{
    std::cout << x <<' '; 
}

template <typename T>
void inc(T &n)
{
    n++;
}

template <typename T>
void sum(const T &x)
{
    static T total = 0;

    total += x;
    std::cout << "tot = " << total << std::endl;
}

int main()
{
    int arr[] = {0, 1, 42, -42, 6767};
    iter(arr, 5, print);
    std::cout << "\n";
    iter(arr, 5, sum);

    iter(arr, 5, inc);
    iter(arr, 5, print);
    std::cout << "\n";


    const char *s = "H1!";
    iter(s, 3, print);
    std::cout << "\n";
    iter(s, 3, sum);

    char s2[] = "ciao";
    iter(s2, 5, print);
    std::cout << "\n";
    iter(s2, 5, inc);
    iter(s2, 5, print);
    std::cout << "\n";

}