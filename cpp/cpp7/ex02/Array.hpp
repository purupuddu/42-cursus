#pragma once

template <typename T>
class Array
{
private:
    T *content;
    unsigned int length;
public:
    Array();
    ~Array();
    Array(const Array &arr);
    Array & operator =(const Array &arr);

    Array(unsigned int n);
    T & operator [](unsigned int i);
    const T & at(unsigned int i) const;
    unsigned int size() const;
    class IndexOutOfRange : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

};

#include "Array.tpp"
