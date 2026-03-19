#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

std::string strip(const std::string &s)
{
    int end = s.length() - 1;
    int beg = 0;
    while(beg <= end && strchr(" \n\r", s[beg]))
        beg++;
    
    while(end > beg && strchr(" \n\r", s[end] ))
        end--;
    if (beg > end)
        return "";
    return s.substr(beg, end - beg + 1);
}

bool is_leap(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool check_valid_date(int year, int month, int day)
{
    if (year < 1900 || month < 1 || month > 12 || day < 1)
        return false;
    switch(month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return day <= 30;
        case 2:
            return day <= 28 || 
                (day == 29 && is_leap(year));
        default:
            return day <= 31;
    }
}

bool check_date_string(std::string date)
{
    std::stringstream ss(date);
    if (date.find(' ') != std::string::npos)
        return false;
    int y, m, d;
    char delim1, delim2;
    ss >> y >> delim1 >> m >> delim2 >> d;
    if(ss.fail() || delim1 != '-' || delim2 != '-' || !ss.eof())
        return false;
    return check_valid_date(y, m, d);
}

void print_conversion(std::string date, double val, BitcoinExchange &b)
{
    if (!check_date_string(date))
    {
        std::cout << "Bad date: " << date << std::endl;
    }
    else if(val < 0)
    {
        std::cout << "value can't be negative" << std::endl;
    }
    else if(val > 1000)
    {
        std::cout << "value can't be above 1000" << std::endl;
    }
    else
    {
        std::cout << date <<" => " << val << " = " <<\
            b.convert(date, val) << std::endl;
    }
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage:"<<argv[0]<<" FILE.txt\n";
        return 1;
    }
    BitcoinExchange b;
    
    std::ifstream in(argv[1]);
    if(!in.good())
    {
        throw std::runtime_error(std::string("No such file: ")+argv[1]);
    }
    
    std::string s;
    std::getline(in, s); // header
    
    while(!in.eof())
    {
        std::string date;
        std::getline(in, s);
        std::stringstream ss(s);
        double val;
        if(s.empty())
        {
            continue;
        }
        std::getline(ss, date, '|');
        date = strip(date);
        if(ss.eof())
        {
            cout << "Format error, missing '|'" << endl;
            continue;
        }
        ss >> val;
        if (ss.fail())
            cout << "Format error, invalid or empty value field" << std::endl;
        else
        {
            print_conversion(date, val, b);
        }
    }
}