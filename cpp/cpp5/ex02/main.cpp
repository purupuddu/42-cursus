#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat giuseppe("Giuseppe", 100);
    Bureaucrat ziopera("Ziopera", 150);
    Bureaucrat toogood("High", 1);
    
    ShrubberyCreationForm tree("tree");
    RobotomyRequestForm *robo = new RobotomyRequestForm("whatever");
    PresidentialPardonForm pard("tax evasion");

    giuseppe.signForm(tree);
    tree.execute(giuseppe);
    toogood.signForm(*robo);
    toogood.signForm(pard);
    toogood.executeForm(*robo);
    ziopera.executeForm(pard);
    toogood.executeForm(pard);
    delete robo;
    // robo.execute(ziopera);
}
