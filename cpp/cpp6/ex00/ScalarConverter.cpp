#include <exception>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cmath>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    throw std::exception();
}

static std::string strip(const std::string &s)
{
    int beg = 0;
    int end = s.length();
    while(isspace(s[end-1]))
        end--;
    while(isspace(s[beg]))
        beg++;
    return s.substr(beg, end-beg);
}

void ScalarConverter::convert(const std::string &s)
{
    std::string stripped = strip(s);
    const char *p = stripped.c_str();
    const char *end;
    int i;
    double d;
    float f;
    bool intok = true;

    if (*p == '\'')
    {
        if(!p[1] || p[2] != '\'' || p[3])
        {
            std::cout << "Not a valid literal\n";
            return;
        }
        d = f = i = p[1];
    }
    else 
    {
        d = strtod(p, (char **)&end);
        if(*end && strcmp(end, "f"))
        {
            std::cout << "Not a valid literal\n";
            return;
        }
        i = f = d;
        
        if (d > INT_MAX || d < INT_MIN || std::isnan(d))
            intok = false;
    }

    if (intok)
    {
        if (i >= 256 || i < 0)
            std::cout << "char: impossible\n";
        else if (isprint(i))
            std::cout << "char: '" << ((char)i) << "'\n";
        else 
           std::cout << "char: Non displayable\n";
       std::cout << "int: " << i << "\n";
    }
    else
    {
           std::cout << "char: impossible\n";
           std::cout << "int: impossible\n";
    }
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}
