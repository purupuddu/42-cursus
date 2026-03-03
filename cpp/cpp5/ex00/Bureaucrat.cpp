#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bob"), grade(1)
{
    std::cout << "Default Bureaucrat: " << *this << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name(b.getName()), grade(b.getGrade())
{
    std::cout << "Copy constructed Bureaucrat: " << *this << "\n";
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat& b) 
{
    // name is const, i can't copy it
    grade = b.getGrade();
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
    checkGrade(grade - 1); // check before for 'strong guarantee'
    grade--;
    std::cout << getName() <<"'s grade has been increased to "<< grade << "\n";
}

void Bureaucrat::decreaseGrade()
{
    checkGrade(grade + 1); // check before for 'strong guarantee'
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
