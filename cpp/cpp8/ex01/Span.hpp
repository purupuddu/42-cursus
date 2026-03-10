#pragma once
#include <iterator>
#include <set>

class Span
{
private:
    unsigned int N;
    unsigned int stored;
    std::set<int> nums;
    unsigned int minSpan;
public:
    Span();
    ~Span();
    Span(const Span &s);
    Span &operator=(const Span &s);
    
    Span(int N);
    void addNumber(int x);
    template <typename T>
    void addRange(T begin, T end);
    int shortestSpan();
    int longestSpan();
    class TooManyNumbers : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
    class NotEnoughNumbers : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
};

template <typename T>
void Span::addRange(T begin, T end)
{
    for(;begin != end;std::advance(begin, 1))
    {
        addNumber(*begin);
    }
}
