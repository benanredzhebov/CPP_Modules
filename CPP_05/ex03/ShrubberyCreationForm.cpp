/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:24:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/10/18 10:50:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm Form", 145, 137), _target("Default target") {
	std::cout << "ShrubberyCreationForm dflt constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm Form", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm dflt destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}	
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}


void	ShrubberyCreationForm::executeForm() const {
	    std::ofstream   o_file((getTarget() + "_ShrubberyCreationForm").c_str());
    o_file  << "                                                  ." << std::endl;
    o_file << "                                              .         ;" << std::endl;
    o_file << "                 .              .              ;%     ;;" << std::endl;
    o_file << "                   ,           ,                :;%  %;" << std::endl;
    o_file << "                    :         ;                   :;%;'     .," << std::endl;
    o_file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    o_file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    o_file << "              %;       %;%;      ,  ;       %;  ;%;   ,%';" << std::endl;
    o_file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    o_file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    o_file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    o_file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    o_file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    o_file << "                        `@%.  `;@%.      ;@@%;" << std::endl;
    o_file << "                          `@%%. `@%%    ;@@%;" << std::endl;
    o_file << "                            ;@%. :@%%  %@@%;" << std::endl;
    o_file << "                              %@bd%%%bd%%:; " << std::endl;
    o_file << "                                #@%%%%%:;;" << std::endl;
    o_file << "                                %@@%%%::;" << std::endl;
    o_file << "                                %@@@%(o);  . '         " << std::endl;
    o_file << "                                %@@@o%;:(.,'         " << std::endl;
    o_file << "                            `.. %@@@o%::;         " << std::endl;
    o_file << "                               `)@@@o%::;         " << std::endl;
    o_file << "                                %@@(o)::;        " << std::endl;
    o_file << "                               .%@@@@%::;         " << std::endl;
    o_file << "                                ;%@@@@%::;.          " << std::endl;
    o_file << "                              ;%@@@@%%:;;;. " << std::endl;
    o_file << "                          ...;%@@@@@%%:;;;;,." << std::endl;
    o_file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try {
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		else
			this->executeForm();
	}
	catch (const std::exception &ex) {
		std::cerr << "Exeption thrown: " << ex.what() << std::endl;
	}
}
