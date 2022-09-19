/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grade.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:28:50 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/19 12:09:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_HPP
# define GRADE_HPP

# include "../colors.hpp"
# include <iostream>
# include <string>

class Grade
{
	public:
		static const Grade	_max_grade;
		static const Grade	_min_grade;
		static const int	_inc_factor;
		
		// Constructors
		Grade();
		Grade(const Grade &copy);
		Grade(int grade);
		
		// Destructor
		~Grade();
		
		// Operators
		Grade & operator=(const Grade &assign);
		
		// Getters / Setters
		int 				getGrade() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		// Logic
		void			increment	( void );
		void			decrement	( void );
		static int		compare		( const Grade& g1, const Grade& g2 );
		
	private:
		int _grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Grade &object);

#endif