#include "Bureaucrat.hpp"


int main()
{
    try {
        Bureaucrat ciro("Ciro", 0);
    } catch (std::exception & e) {
        std::cerr << "catching Ciro: " << e.what() << std::endl; 
    }
    try {
        Bureaucrat ciro2("Ciro2", 200);
    } catch (std::exception & e) {
        std::cerr << "catching Ciro2: " << e.what() << std::endl; 
    }

    Bureaucrat giuseppe("Giuseppe", 100);
    Bureaucrat ziopera("Ziopera", 150);
    Bureaucrat toogood("High", 1);

    try {
        toogood.increaseGrade();
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << "High is too good: " << e.what() << std::endl;
    }
    std::cout << toogood << std::endl;
    ziopera.increaseGrade();

    try {
        giuseppe.increaseGrade();
    } catch (std::exception & e) {
        std::cout<<"nothing wrong here\n";
    }

    ziopera.decreaseGrade();
    std::cout << "And now we will just die because, why not?" << std::endl;
    ziopera.decreaseGrade();
}
