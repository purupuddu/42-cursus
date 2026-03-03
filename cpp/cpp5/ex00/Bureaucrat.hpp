#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;

    public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const Bureaucrat& b);
    Bureaucrat &operator = (const Bureaucrat& b);
    ~Bureaucrat();
    
    Bureaucrat(std::string name, int grade);
    const std::string &getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
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
};

std::ostream & operator << (std::ostream &stream, const Bureaucrat &b);
void checkGrade(int grade);