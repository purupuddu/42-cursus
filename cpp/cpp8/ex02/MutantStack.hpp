#pragma once
#include <stack>

// template <typename T>

template<typename T, typename _Sequence = std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
    typedef typename _Sequence::iterator iterator;

    iterator begin();
    iterator end();

};

template<typename T, typename _Sequence>
typename MutantStack<T, _Sequence>::iterator MutantStack<T, _Sequence>::begin()
{
    return this->c.begin();
}

template<typename T, typename _Sequence>
typename MutantStack<T, _Sequence>::iterator MutantStack<T, _Sequence>::end()
{
    return this->c.end();
}

