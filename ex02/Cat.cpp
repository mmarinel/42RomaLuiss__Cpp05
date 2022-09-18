/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:09:22 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 11:13:30 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound( void ) const
{
	this->__next_idea = (this->__next_idea + 1) % IDEAS_SIZE;
	print_line(
		"Meow.. ...thinking of "
			+ this->brain->get_idea(this->__next_idea),
		YELLOW
	);
}

void	Cat::emptyMind( void )
{
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		this->brain->set_idea("numb", i);
}

const Animal&	Cat::operator =	( const Animal& to_copy )
{

	print_line("Cat- Animal Copy assignment Operator", YELLOW);

	const Cat	*as_cat = dynamic_cast<const Cat *>(&to_copy);

	if (nullptr == as_cat)
		this->Animal::operator=(to_copy);
	else
		this->operator=(*as_cat);
	
	return (*this);
}

const Cat&	Cat::operator	=	( const Cat& to_copy)
{
	print_line("Cat- Copy Assignment Operator", YELLOW);

	this->__next_idea = -1;
	this->type.assign(to_copy.type);
	this->brain = to_copy.brain;

	return (*this);
}

Cat::Cat( const Cat& to_copy )
{
	print_line("Cat- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

Cat::Cat()
{
	print_line("Cat- Default Constructor", BOLDGREEN);

	this->__next_idea = -1;
	this->type.assign("Cat");
	this->brain = new Brain();

	for (size_t i = 0; i < IDEAS_SIZE; i++)
		if (i % 2 == 0)
			this->brain->set_idea("catnip", i);
		else
			this->brain->set_idea("tuna", i);
}

Cat::~Cat()
{
	delete this->brain;
	print_line("<<Cat Destroyed>>", BOLDRED);
}
