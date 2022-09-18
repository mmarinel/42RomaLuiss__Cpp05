/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:59:19 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 10:31:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::makeSound( void ) const
{
	this->__next_idea = (this->__next_idea + 1) % IDEAS_SIZE;
	print_line(
		"Bark bark! ...thinking of "
			+ this->brain->get_idea(this->__next_idea),
		YELLOW
	);
}

const std::string&	Dog::oneVeryImportantThought( void ) const
{
	return (this->brain->get_idea(0));
}

void	Dog::emptyMind( void )
{
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		this->brain->set_idea("numb", i);
}

const Animal&	Dog::operator =	( const Animal& to_copy )
{
	print_line("Dog- Animal Copy assignment Operator", YELLOW);

	const Dog	*as_dog = dynamic_cast<const Dog *>(&to_copy);

	if (nullptr == as_dog)
		this->Animal::operator=(to_copy);
	else
		this->operator=(*as_dog);

	return (*this);
}

const Dog&	Dog::operator	=	( const Dog& to_copy)
{
	print_line("Dog- Copy Assignment Operator", YELLOW);

	this->__next_idea = -1;
	this->type.assign(to_copy.type);
	*(this->brain) = *to_copy.brain;

	return (*this);
}

Dog::Dog( const Dog& to_copy )
{
	print_line("Dog- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

Dog::Dog()
{
	print_line("Dog- Default Constructor", BOLDGREEN);

	this->__next_idea = -1;
	this->type.assign("Dog");
	this->brain = new Brain();

	for (size_t i = 0; i < IDEAS_SIZE; i++)
	{
		if (i % 2 == 0)
			this->brain->set_idea("Bone", i);
		else
			this->brain->set_idea("Cat", i);
	}
}

Dog::~Dog()
{
	delete this->brain;
	print_line("<<Dog Destroyed>>", BOLDRED);
}
