/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:54:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/19 11:16:20 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grade.hpp"

const Grade Grade::_max_grade = Grade(1);
const Grade Grade::_min_grade = Grade(150);
const int	Grade::_inc_factor = -1;

// Constructors
Grade::Grade()
{
	this->_grade = Grade::_min_grade.getGrade();

	std::cout << "\e[0;33mDefault Constructor called of Grade\e[0m" << std::endl;
}

Grade::Grade(const Grade &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Grade\e[0m" << std::endl;

	this->_grade = copy._grade;
}

Grade::Grade( int grade )
{
	std::cout << "\e[0;33mFields Constructor called of Grade\e[0m" << std::endl;

	this->_grade = grade;
	if (Grade::compare(*this, Grade::_max_grade) > 0)
		throw Grade::GradeTooHighException();
	if (Grade::compare(*this, Grade::_min_grade) < 0)
		throw Grade::GradeTooLowException();
}

// Destructor
Grade::~Grade()
{
	std::cout << "\e[0;31mDestructor called of Grade\e[0m" << std::endl;
}

// Operators
Grade & Grade::operator=(const Grade &assign)
{
	_grade = assign.getGrade();
	return *this;
}

// Getters / Setters
int Grade::getGrade() const
{
	return _grade;
}

const Grade& Grade::getMax_grade()
{
	return Grade::_max_grade.getGrade();
}
const Grade& Grade::getMin_grade()
{
	return Grade::_min_grade.getGrade();
}

// Exceptions
const char * Grade::GradeTooHighException::what() const throw()
{
	return BOLDRED "Grade: grade too high" RESET;
}
const char * Grade::GradeTooLowException::what() const throw()
{
	return BOLDRED "Grade: grade too low" RESET;
}

//Logic
int	compare( const Grade& g1, const Grade& g2 )
{
	return (-1) * (g1.getGrade() - g2.getGrade());
}

void	Grade::increment( void )
{
	if (Grade::compare(*this, Grade::getMax_grade()) > 0)
		throw Grade::GradeTooHighException();
	else
		this->_grade += Grade::_inc_factor;
}

void	Grade::decrement( void )
{
	if (Grade::compare(*this, Grade::getMin_grade()) < 0)
		throw Grade::GradeTooLowException();
	else
		this->_grade -= Grade::_inc_factor;
}

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Grade &object)
{
	stream << "grade: " << object.getGrade() << std::endl;
	return stream;
}
