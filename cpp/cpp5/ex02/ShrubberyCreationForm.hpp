#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    const std::string target;
public:
    const std::string &getTarget() const;
    ShrubberyCreationForm(std::string target);
    virtual void execute(Bureaucrat const & executor) const;
};