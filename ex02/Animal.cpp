/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:55:21 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 11:24:12 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

const Animal&	Animal::operator	=	( const Animal& to_copy )
{
	print_line("Animal- Copy Assignment Operator", YELLOW);

	this->type.assign(to_copy.type);

	return (*this);
}

Animal::Animal( const Animal& to_copy )
{
	print_line("Animal- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

Animal::Animal()
{
	print_line("Animal- Default Constructor", BOLDGREEN);

	this->type.assign("Meta");
}

Animal::~Animal()
{
	print_line("<<Animal Destroyed>>", BOLDRED);
}

const std::string&	Animal::getType( void ) const
{
	return (this->type);
}
