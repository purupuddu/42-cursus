#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern()\n";
}

Intern::~Intern()
{
    std::cout << "~Intern()\n";
}

Intern::Intern(const Intern &intern)
{
    (void)intern;
    std::cout << "Free boilerplate code\n";
}

Intern &Intern::operator = (const Intern &intern)
{
    (void)intern;
    std::cout << "Free boilerplate code\n";
    return *this;
}

AForm *Intern::makeForm(const std::string & name, const std::string & target)
{
    std::string names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    std::string namelower = name;
    for (size_t i = 0; i < name.length(); i++)
        namelower[i] = tolower(namelower[i]);

    int choice = -1;
    for (int i = 0; i < 3; i++)
    {
        if (names[i] == namelower)
        {
            choice = i;
            break;
        }
    }
    switch(choice)
    {
        case 0: return new RobotomyRequestForm(target);
        case 1: return new ShrubberyCreationForm(target);
        case 2: return new PresidentialPardonForm(target);
        default: return NULL;
    }
}
