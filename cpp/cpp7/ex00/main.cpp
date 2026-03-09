#include "whatever.hpp"
#include <iostream>

template <typename T>
void test(T a, T b)
{
    std::cout << a << ' ' << b << std::endl;
    swap(a, b);
    std::cout << "after swap\n";
    std::cout << a << ' ' << b << std::endl;
    /*
    Peak c++ features: let's give an option to not put the namespace
    if the argument's already in the namespace. Now min has two candidates
    and i have to use ::min and ::max for a stupid feature i didn't know about,
    is useless in 90% of the cases, breaks style, and sometimes blows you
    up with conflicts for no fucking reason. I can't understand why it doesn't default
    to golbal namespace either. But I still need to put std:: in front of everything. 
    Thanks c++
    */
   std::cout << "min("<<a<<", "<<b<<") = " << ::min(a, b) << std::endl;
   std::cout << "max("<<a<<", "<<b<<") = " << ::max(a, b) << std::endl;
}

int main()
{
    std::cout << "begin subject test\n";
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    std::cout << "end subject test\n";
    
    std::cout << "=======================\n";
    test(10, 42);
    std::cout << "=======================\n";
    test('A', 'Z');
    std::cout << "=======================\n";
    std::cout << "wrong version, compares the pointers\n";
    test("hello", "bye"); 
    std::cout << "=======================\n";
    
    std::cout << "correct version, uses string operator<\n";
    test<std::string>("hello", "bye");
    std::cout << "=======================\n";
    test(3.14, 1.2345);
    std::cout << "=======================\n";
    test(3.14, 0.0/0.0);
}