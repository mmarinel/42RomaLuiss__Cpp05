/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 12:04:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("nameless", false, 145, 137)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;

	*this = copy;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	this->target.assign(assign.target);
	this->Form::operator=(assign);

	return (*this);
}


// Logic
void	ShrubberyCreationForm::action( void ) const
{
	std::ofstream	target (this->target + "_shrubbery");

	target
	<< "     _-_ \
    /~~   ~~\ \
 /~~         ~~\ \
{               } \
 \  _-     -_  / \
   ~  \\ //  ~ \
_- -   | | _- _ \
  _ -  | |   -_ \
      // \\ \
"
	<< std::endl
	<< "     _-_ \
    /~~   ~~\ \
 /~~         ~~\ \
{               } \
 \  _-     -_  / \
   ~  \\ //  ~ \
_- -   | | _- _ \
  _ -  | |   -_ \
      // \\ \
";
	target.close();
}