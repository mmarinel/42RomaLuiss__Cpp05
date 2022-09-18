/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/18 20:07:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main()
{
	try
	{
		
		Bureaucrat	maria_ardolino;
		Bureaucrat	nicla_terlizzi ("nicla", 5);
		Bureaucrat	nicla_clone (nicla_terlizzi);
		Bureaucrat	maria_clone (maria_ardolino);

		std::cout
			<< maria_ardolino << maria_clone
			<< nicla_terlizzi << nicla_clone;

		Bureaucrat	unvalid ("pippo", 0);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	pippa ("pippa", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& b)
	{
		std::cerr << b.what() << '\n';
	}
	

	std::cout << std::endl;
	Bureaucrat	nicla_terlizzi ("nicla", 5);
	try
	{
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
		nicla_terlizzi.increment();
		std::cout << nicla_terlizzi << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
