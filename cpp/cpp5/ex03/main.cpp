#include <cassert>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat giuseppe("Giuseppe", 100);
    Bureaucrat ziopera("Ziopera", 150);
    Bureaucrat toogood("High", 1);
    
    Intern alessandro;

    AForm * a = alessandro.makeForm("finto", "finto");
    AForm * b = alessandro.makeForm("rOboTomy rEquest", "my brain after this cpp");
    AForm * c = alessandro.makeForm("shrubbery creation", "at_home");
    AForm * d = alessandro.makeForm("Presidential Pardon", "eating all the biscuits");

    assert(a == NULL);
    toogood.signForm(*b);
    toogood.executeForm(*b);
    toogood.signForm(*c);
    toogood.executeForm(*c);
    toogood.signForm(*d);
    toogood.executeForm(*d);
    delete b;
    delete c;
    delete d;
}
