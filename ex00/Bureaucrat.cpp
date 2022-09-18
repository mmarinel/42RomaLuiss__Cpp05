/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:42:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/18 20:04:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("nameless")
{
	_grade = BC_MAX_GRADE;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;

	if (grade BC_HIGHER BC_MAX_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade BC_LESSER BC_MIN_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	print_line("Bureaucrat- Copy Assignment Operator", YELLOW);

	::new (this) Bureaucrat(assign);//* :: means "use the new in the global namespace"---NEW EXPRESSION vs new operator (https://en.cppreference.com/w/cpp/language/new)

	return *this;
}

// Getters / Setters
const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// Logic
void	Bureaucrat::increment( void )
{
	if (this->_grade == BC_MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade += BC_INC_FACTOR;
}

void	Bureaucrat::decrement( void )
{
	if (this->_grade == BC_MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade -= BC_INC_FACTOR;
}

// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too high" RESET;
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too low" RESET;
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl;
	return stream;
}
