#include "AForm.hpp"

AForm::AForm() : name("Generic Form"), sign(false), gradeSign(50), gradeExec(100)
{
    std::cout << "AForm() = " << *this << "\n";
}

AForm::AForm(AForm &f) : name(f.name), sign(f.sign), gradeSign(f.gradeSign), gradeExec(f.gradeExec)
{
    std::cout << "AForm(f) = " << *this << "\n";
}

const AForm &AForm::operator =(AForm &f)
{
    sign = f.getSign();
    std::cout<< "Just copy the sign " << *this << "\n"; 
    return *this;
}

AForm::~AForm()
{
    std::cout << "~AForm() : " << *this << "\n";
} 


AForm::AForm(const std::string & name, int gradeSign, int gradeExec) :
    name(name), sign(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    checkFGrade(gradeSign);
    checkFGrade(gradeExec);
    std::cout << "AForm(...) = " << *this << "\n";
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(sign)
        return;
    if(b.getGrade() > getGradeSign())
        throw GradeTooLowException();
    sign = true;
}

std::ostream & operator << (std::ostream &stream, const AForm &f)
{
    return stream << "AForm " << f.getName() << ", " << (f.getSign()? "signed" : "not signed")\
        << ", grade to sign = "<< f.getGradeSign() << ", grade to execute = " << f.getGradeSign();
}

const std::string AForm::getName() const {
    return name;
}

bool AForm::getSign() const {
    return sign;
}

int AForm::getGradeSign() const {
    return gradeSign;
}

int AForm::getGradeExec() const {
    return gradeExec;
}

void checkFGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}


const char * AForm::GradeTooLowException::what() const throw()
{
    return "AForm:: Grade too low";
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "AForm:: Grade too high";
}
