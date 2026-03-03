#pragma once
#include <string>
#include "Bureaucrat.hpp"


class AForm
{
private:
    const std::string name;
    bool sign;
    const int gradeSign;
    const int gradeExec;

public:
    AForm();
    AForm(AForm &f);
    const AForm &operator =(AForm &f);
    virtual ~AForm() = 0; 

    AForm(const std::string & name, int gradeSign, int gradeExec);
    const std::string getName() const;
    bool getSign() const;
    int getGradeSign() const;
    int getGradeExec() const;
    void beSigned(const Bureaucrat &b);
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator << (std::ostream &stream, const AForm &b);
void checkFGrade(int grade);

