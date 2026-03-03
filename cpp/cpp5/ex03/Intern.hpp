#pragma once
#include "AForm.hpp"

class Intern 
{
public:
    AForm *makeForm(const std::string & name, const std::string & target);
    Intern();
    ~Intern();
    Intern(const Intern &intern);
    Intern &operator = (const Intern &intern);

};