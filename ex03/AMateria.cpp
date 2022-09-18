/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:20:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 11:00:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
const AMateria&	AMateria::operator = ( const AMateria& to_copy )
{
	print_line("AMateria: Copy Assignment Operator", YELLOW);

	return (*this);
}
#pragma GCC diagnostic pop

AMateria::AMateria	( AMateria const & to_copy ) : type(to_copy.type)
{
	print_line("AMateria: Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

AMateria::AMateria( std::string const & type ) : type(type)
{
	print_line("AMateria: std::string Constructor", BOLDGREEN);
}

AMateria::AMateria() : type("typeless")
{
	print_line("AMateria: Default Constructor", BOLDGREEN);
}

AMateria::~AMateria()
{
	print_line("<<AMateria Destroyed>>", BOLDRED);
}

void	AMateria::use( ICharacter& target )
{
	std::cout
	<< YELLOW
	<< "* Cast a generic spell at "
	<< target.getName() << "*"
	<< RESET
	<< std::endl;
}

std::string const &	AMateria::getType( void ) const
{
	return (this->type);
}
