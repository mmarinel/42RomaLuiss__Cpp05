/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/18 17:40:50 by mmarinel         ###   ########.fr       */
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';

		try
		{
			Bureaucrat	pippa ("pippa", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return 0;
}
