#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    const std::string target;
public:
    const std::string &getTarget() const;
    PresidentialPardonForm(std::string target);
    virtual void execute(Bureaucrat const & executor) const;
};