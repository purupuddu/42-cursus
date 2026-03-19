#pragma once
#include <string>

class RPN{
    private:
        std::string expr;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &rpn);
        const RPN& operator = (const RPN &rpn);
        RPN(const std::string &expr);
        int calc() const;
    
};
