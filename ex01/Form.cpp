/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:44:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/22 20:25:53 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form()
	: _name("nameless"),
	_sign_grade(Grade::_min_grade), _exec_grade(Grade::_min_grade)
{
	// std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;

	_is_signed = false;
}

Form::Form(const Form &copy)
	: _name(copy._name),
	_sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	// std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;

	_is_signed = copy.getIs_signed();
}

Form::Form(
	const std::string name,
	bool is_signed,
	const int sign_grade,
	const int exec_grade
)
	try
		: _name(name),
		_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	// std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;

	_is_signed = is_signed;
}
catch (const Grade::GradeTooLowException& e) {
	throw Form::GradeTooLowException();//! Subject is dumb and made me do this!
}
catch (const Grade::GradeTooHighException& e) {
	throw Form::GradeTooHighException();//! Subject is dumb and made me do this!
}


// Destructor
Form::~Form()
{
	// std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	(void) assign;

	this->~Form();
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
const Grade Form::getSign_grade() const
{
	return _sign_grade;
}
const Grade Form::getExec_grade() const
{
	return _exec_grade;
}

// Logic
void	Form::beSigned( const Bureaucrat &br )
{
	if (Grade::compare(br.getGrade(), this->_sign_grade) < 0)
		throw Form::SignGradeTooLowException();
	else
		this->_is_signed = true;
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream
		<< "{\n"
		<< "\tform name: "<< object.getName() << ",\n"
		<< "\tis signed: " << object.getIs_signed() << ",\n"
		<< "\tgrade to sign: " << object.getSign_grade().getGrade() << ",\n"
		<< "\tgrade to execute: " << object.getExec_grade().getGrade() << ",\n"
		<< "}\n"
		<< std::endl;
	return stream;
}
