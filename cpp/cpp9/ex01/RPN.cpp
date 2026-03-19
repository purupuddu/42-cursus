#include "RPN.hpp"
#include <stack>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <exception>

int RPN::calc() const
{
    std::stack<int> st;

    for(std::string::const_iterator it = expr.begin();it != expr.end() ;it++)
    {
        if(isdigit(*it))
        {
            st.push(*it - '0');
            continue;
        }
        if(isspace(*it))
            continue;
        if (!strchr("+-/*", *it))
                throw std::runtime_error((std::string("Unsupported token: '") + *it + "'").c_str());
        if(st.size() < 2)
        {
            throw std::runtime_error("Malformed expression, not enough operands "
                "to execute the operation\n");
        }
        int b = st.top();st.pop();
        int a = st.top();st.pop();
        switch(*it)
        {
            case '+':st.push(a + b);break;
            case '-':st.push(a - b);break;
            case '*':st.push(a * b);break;
            case '/':st.push(a / b);break;
            default:
                throw std::runtime_error((std::string("Unsupported token: '") + *it + "'").c_str());
        }
    }
    if(st.size() > 1)
    {
        throw std::runtime_error("Malformed operation, #operands > #operators-1\n");
    }
    if (st.size() == 0)
    {
        throw std::runtime_error("Empty expression\n");
    }
    return st.top();
}


RPN::RPN() : expr("67*")
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

const RPN& RPN::operator = (const RPN &rpn)
{
    expr = rpn.expr;
    return *this;
}

RPN::RPN(const std::string & s) : expr(s)
{}
