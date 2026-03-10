#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    sp.addNumber(6);
    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    sp.addNumber(3);

    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
    
    sp.addNumber(17);
    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
    sp.addNumber(9);
    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
    
    try
    {
        sp.addNumber(15);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    int v[] = {1, 3, 5, 7, 42};
    sp = Span(10);
    sp.addRange(v, v+5);
    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;
    Span copy(sp);
    sp.addNumber(-42);
    sp.addNumber(-42);
    std::cout << sp.shortestSpan() << " " << sp.longestSpan() << std::endl;

    copy.addNumber(0);
    std::cout << copy.shortestSpan() << " " << copy.longestSpan() << std::endl;
    
}