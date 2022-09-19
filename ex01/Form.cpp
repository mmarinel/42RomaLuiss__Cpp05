/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:44:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/19 10:25:08 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() : _name("nameless"), _sign_grade(150), _exec_grade(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;

	_is_signed = false;
}

Form::Form(const Form &copy)
	: _name(copy._name), _sign_grade(copy._sign_grade),
		_exec_grade(copy._exec_grade)
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;

	_is_signed = copy.getIs_signed();
}

Form::Form(
	const std::string name,
	bool is_signed,
	const int sign_grade,
	const int exec_grade
)
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;

	if (sign_grade BC_HIGHER BC_MAX_GRADE)
		throw Form::GradeTooHighException();
	if (sign_grade BC_LESSER BC_MIN_GRADE)
		throw Form::GradeTooLowException();
	_is_signed = is_signed;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	::new(this) Form(assign);
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getIs_signed() const
{
	return _is_signed;
}
const int Form::getSign_grade() const
{
	return _sign_grade;
}
const int Form::getExec_grade() const
{
	return _exec_grade;
}

// Logic
void	Form::beSigned( const Bureaucrat &br )
{
	if (br.getGrade() BC_LESSER this->_sign_grade)
		throw Form::GradeTooLowException();
	else
		this->_is_signed = true;
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Form: grade too high";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Form: grade too low";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream
		<< "form name: "<< object.getName()
		<< ", is signed: " << object.getIs_signed()
		<< ", grade to sign: " << object.getSign_grade()
		<< ", grade to execute: " << object.getExec_grade()
		<< std::endl;
	return stream;
}
