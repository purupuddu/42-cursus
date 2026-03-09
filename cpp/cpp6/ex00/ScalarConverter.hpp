#pragma once
#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
public:
    static void convert(const std::string &s);

    enum ScalarType { INT, CHAR, DOUBLE, FLOAT, NONE};
};