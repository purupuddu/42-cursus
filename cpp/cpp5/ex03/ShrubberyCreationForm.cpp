#include <string>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
    AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout<<"ShrubberyCreationForm() = " << *this << ", target = " << getTarget() << "\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    const char* tree = "           ,\n"
    "          / \\\n"
    "        .'   '.\n"
    "       /       \\\n"
    "      /.-.   .-.\\\n"
    "      `/  '.'   \\`\n"
    "     .'          '.\n"
    "    /.--.     .--.\\\n"
    "    `/   '. .'    \\`\n"
    "   .'      `       '.\n"
    "  /.---.       .----.\\\n"
    "  `/    `.   .'     \\`\n"
    " .'       `.'        '.\n"
    "/,----,          ,----,\\\n"
    "`'-.__.;-,____,-;.__.-'\n"
    "         |||||\n"
    "         |||||\n"
    "         `\"\"\"`\n";

    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();
    std::string filename = getTarget()+"_shrubbery";
    std::ofstream out(filename.c_str());
    out << tree;
    out.close();
}

const std::string &ShrubberyCreationForm::getTarget() const { return target; }
