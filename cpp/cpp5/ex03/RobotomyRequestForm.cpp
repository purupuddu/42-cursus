#include <string>
#include <fstream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
    AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout<<"RobotomyRequestForm() = " << *this << ", target = " << getTarget() << "\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static bool rand_init = false;

    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    if (!rand_init)
    {
        srand(time(0));
        rand_init = true;
    }
    
    std::cout << "BRRRRT BRRRRT- "
        <<"(WOW THAT SOUNDS EXACTLY LIKE A DRILLING NOISE!!)\n";
    
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized succesfully\n";
    else
        std::cout << getTarget() << " robotomization failed\n";
}

const std::string &RobotomyRequestForm::getTarget() const { return target; }
