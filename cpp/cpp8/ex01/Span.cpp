#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : N(10), stored(0), nums(), minSpan(UINT_MAX)
{}

Span::~Span()
{}

Span::Span(const Span &s)
{
    *this = s;
}

Span & Span::operator=(const Span &s)
{
    N = s.N;
    stored = s.stored;
    nums = s.nums;
    minSpan = s.minSpan;
    return *this;
}

Span::Span(int N) : N(N), stored(0), nums(), minSpan(UINT_MAX)
{}

void Span::addNumber(int x)
{
    if (stored >= N)
    {
        throw TooManyNumbers();
    }
    std::set<int>::iterator it = nums.lower_bound(x);
    if (it != nums.end())
    {
        minSpan = std::min(minSpan, static_cast<unsigned int>(*it - x));
    }
    if (it != nums.begin())
    {
        it--; // since it pointed at the first element >= x 
        // now it will point to the last element < x
        minSpan = std::min(minSpan, static_cast<unsigned int>(x - *it));
    }
    nums.insert(x);
    stored++;
}

int Span::shortestSpan()
{
    if (stored < 2)
        throw NotEnoughNumbers();

    return minSpan;
}

int Span::longestSpan()
{
    if (stored < 2)
        throw NotEnoughNumbers();
    return *nums.rbegin() - *nums.begin();
}


const char * Span::TooManyNumbers::what() const throw()
{
    return "The structure is full and no more numbers can be added";
}

const char * Span::NotEnoughNumbers::what() const throw()
{
    return "Need at least 2 elements to contain a span";
}
