#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Bob"), grade(1)
{
    std::cout << "Default Bureaucrat: " << *this << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name("Bob"), grade(1)
{
    *this = b;
    std::cout << "Copy constructed Bureaucrat: " << *this << "\n";
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat& b) 
{
    grade = b.getGrade();
    name = b.getName();
    std::cout << "Copied Bureaucrat: "<< b << "\n";
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Destroying Bureaucrat: "<< *this << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    checkGrade(grade);
    std::cout<<"Created Bureaucrat: " << *this << "\n";
}

const std::string &Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const 
{
    return grade;
}

std::ostream & operator << (std::ostream &stream, const Bureaucrat &b) 
{
    return stream << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
}

void Bureaucrat::increaseGrade()
{
    checkGrade(grade - 1);
    grade--;
    std::cout << getName() <<"'s grade has been increased to "<< grade << "\n";
}

void Bureaucrat::decreaseGrade()
{
    checkGrade(grade + 1);
    grade++;
    std::cout << getName() <<"'s grade has been decreased to "<< grade << "\n";
}

void checkGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.getSign())
    {
        std::cout << form.getName() << " was already signed\n";
        return;
    }
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "\n";
    } catch (AForm::GradeTooLowException & e)
    {
        std::cout << name << " couldn't sign " << form.getName() \
            << " because " << e.what() << ".\n";
    }
}


void Bureaucrat::executeForm(const AForm &form) const
{
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << "\n"; 
    } catch (std::exception &e)
    {
        std::cout << getName() << " couldn't execute " << form.getName() \
            << " because " << e.what() << "\n";
    }
}
