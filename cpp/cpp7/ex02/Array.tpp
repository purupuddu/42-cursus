

#pragma once
#include <exception>

template <typename T>
Array<T>::Array() : content(0), length(0)
{

}

template <typename T>
Array<T>::~Array()
{
    delete[] content;
}

template <typename T>
Array<T>::Array(const Array<T> &arr) : content(0), length(0)
{
    *this = arr;
}

template <typename T>
Array<T> & Array<T>::operator =(const Array<T> &arr)
{
    delete content;
    length = arr.size();
    content = new T[length];
    for(unsigned int i = 0; i < length; i++)
        content[i] = arr.at(i);
    return *this;
}


template <typename T>
Array<T>::Array(unsigned int n) : content(new T[n]), length(n)
{
    for(unsigned int i = 0; i < n; i++)
    {
        content[i] = T();
    }
}

template <typename T>
T & Array<T>::operator [](unsigned int i)
{
    if (i >= length)
        throw IndexOutOfRange();
    return content[i];
}

template <typename T>
const T & Array<T>::at(unsigned int i) const
{
    if (i >= length)
        throw IndexOutOfRange();
    return content[i];
}


template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}

template <typename T>
const char * Array<T>::IndexOutOfRange::what() const throw()
{
    return "Index out of range";
}

