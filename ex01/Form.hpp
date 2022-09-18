/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:30:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/18 20:54:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, bool is_signed,
			const int sign_grade, const int exec_grade);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		const std::string getName() const;
		bool getIs_signed() const;
		const int getSign_grade() const;
		const int getExec_grade() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif