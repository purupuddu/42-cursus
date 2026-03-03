#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat giuseppe("Giuseppe", 100);
    Bureaucrat ziopera("Ziopera", 150);
    Bureaucrat toogood("High", 1);
    
    AForm base("b", 150, 150);
    AForm easy("easy", 100, 150);
    AForm hard("hard", 1, 1);

    giuseppe.signForm(hard);
    giuseppe.signForm(easy);
    ziopera.signForm(base);
    ziopera.signForm(easy);
    toogood.signForm(hard);
}
