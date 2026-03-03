#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string target;
public:
    const std::string &getTarget() const;
    RobotomyRequestForm(std::string target);
    virtual void execute(Bureaucrat const & executor) const;
};