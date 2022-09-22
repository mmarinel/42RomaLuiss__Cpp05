/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/22 14:24:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

#include <fstream>
#include <iostream>
#include <string>

static Bureaucrat*	read_bureaucrat( void );
static Form*		read_form( void );
//* end of static declarations

int	main()
{
	Bureaucrat	*bur;
	Form		*form;
	bool		repeat;

	std::cin.exceptions(std::ios_base::badbit | std::ios_base::eofbit);
	try {
		repeat = true;
		while (repeat)
		{
			try {
				bur = read_bureaucrat();
				form = read_form();
				bur->signForm(*form);
				bur->executeForm(*form);
				repeat = false;
			}
			catch (std::exception &e) {
				std::cout << "\npress any key to retry..." << std::endl;
				getchar();
			}
			delete bur;
			delete form;
		}
	}
	catch (std::istream::failure &e) {
		std::cout << "eof caught or stream broken" << std::endl;
	}
	return 0;
}

static Bureaucrat*	read_bureaucrat( void )
{
	Bureaucrat*	bur;
	bool		repeat;
	std::string	bur_name;
	int			bur_grade;

	repeat = true;
	while (repeat)
	{
		read_string(bur_name, "enter bureaucrat name");
		read_input(&bur_grade, int, "insert bureaucrat grade");
		try {
			bur = new Bureaucrat(bur_name, bur_grade);
			repeat = false;
		}
		catch (std::exception& e) {
			std::cout << "Invalid bureaucrat data: " << e.what() << std::endl;
			std::cout << "Press any key to retry...";
			std::getchar();
			std::cout  << std::endl;
		}
	}
	return (bur);
}

static Form*	read_form( void )
{
	Form*		form;
	Intern		intern;
	std::string	formName;
	std::string	target;

	while (true)
	{
		read_string(target, "choose target name");
		read_string(formName, "choose form name");
		form = intern.makeForm(formName, target);
		if (nullptr == form)
		{
			std::cout << "Press Any key to retry";
			std::getchar();
			std::cout << std::endl;
		}
		else
			break ;
	}
	return  (form);
}
