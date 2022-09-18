/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 15:35:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

void	Cure::use( ICharacter& target )
{
	std::cout
		<< CYAN
		<< "* heals " << target.getName() << "'s wounds *"
		<< RESET
		<< std::endl;
}

AMateria*	Cure::clone( void ) const
{
	print_line("Cure- clone", YELLOW);

	Cure*	copy = new Cure();

	return (copy);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
const Cure&	Cure::operator = ( const Cure& to_copy )
{
	print_line("Cure- Copy Assignment Operator", YELLOW);

	return (*this);
}
#pragma GCC diagnostic pop

Cure::Cure( const Cure& to_copy ) : AMateria(to_copy.type)
{
	print_line("Cure- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

Cure::Cure() : AMateria("cure")
{
	print_line("Cure- Default Constructor", BOLDGREEN);
}

Cure::~Cure()
{
	print_line("<<Cure Destroyed>>", BOLDRED);
}
