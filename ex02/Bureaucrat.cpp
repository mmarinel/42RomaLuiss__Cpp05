/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:42:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/21 12:28:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("nameless")
{
	_grade = Grade::_min_grade;
	// std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy.getGrade();
	// std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	// std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;

	try {
		this->_grade = Grade(grade);//* MAY THROW EXCEPTION !!!!!!!!!!
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		throw ;//! Subject is dumb and made me do this!
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		throw ;//! Subject is dumb and made me do this!
	}
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	// print_line("Bureaucrat- Copy Assignment Operator", YELLOW);

	::new (this) Bureaucrat(assign);//* :: means "use the new in the global namespace"---NEW EXPRESSION vs new operator (https://en.cppreference.com/w/cpp/language/new)

	return *this;
}

// Getters / Setters
const std::string Bureaucrat::getName() const
{
	return _name;
}

const Grade Bureaucrat::getGrade() const
{
	return _grade;
}

// Logic
void	Bureaucrat::increment( void )
{
	try {
		this->_grade.increment();//* may throw Exception!
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		throw ;//! Subject is dumb and made me do this!
	}
}

void	Bureaucrat::decrement( void )
{
	try {
		this->_grade.decrement();//* may throw Exception!
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		throw ;//! Subject is dumb and made me do this!
	}
}

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned(*this);
		std::cout
			<< GREEN
			<< this->_name << " signed " << form//.getName()
			<< RESET
			<< std::endl;
	}
	catch(const Form::SignGradeTooLowException& e)
	{
		std::cout
			<< RED
			<< this->_name << " couldn't sign " << form//.getName()
			<< " because " << e.what()
			<< RESET
			<< std::endl;
	}
	
}
void	Bureaucrat::executeForm( Form const &form )
{
	try
	{
		form.execute(*this);
		std::cout
			<< GREEN
			<< this->_name << " executed " << form//.getName()
			<< RESET
			<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout
			<< RED
			<< this->_name << " could not execute " << form//.getName()
			<< RESET
			<< std::endl;
		throw ;
	}
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << std::endl;
	return stream;
}
