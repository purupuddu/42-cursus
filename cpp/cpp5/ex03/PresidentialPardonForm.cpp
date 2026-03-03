#include <string>
#include <fstream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
    AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout<<"PresidentialPardonForm() = " << *this << ", target = " << getTarget() << "\n";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}

const std::string &PresidentialPardonForm::getTarget() const { return target; }
