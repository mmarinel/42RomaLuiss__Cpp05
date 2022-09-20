/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:08:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 10:45:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Grade.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

// Grade
const char * Grade::GradeTooHighException::what() const throw()
{
	return BOLDRED "Grade: grade too high" RESET;
}
const char * Grade::GradeTooLowException::what() const throw()
{
	return BOLDRED "Grade: grade too low" RESET;
}

// Bureaucrat
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too high" RESET;
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return BOLDRED "Bureaucrat: grade too low" RESET;
}

// Form
const char * Form::GradeTooLowException::what() const throw()
{
	return ("Form: grade too low for creation");
}
const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form: grade too high for creation");
}
const char * Form::SignGradeTooLowException::what() const throw()
{
	return ("Form: grade too low for signing");
}
const char * Form::ExecGradeTooLowException::what() const throw()
{
	return ("Form: grade too high for executing");
}
