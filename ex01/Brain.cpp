/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:50:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 10:50:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

const Brain&	Brain::operator	= 	( const Brain& br )
{
	print_line("Brain- Copy Assignment Operator", YELLOW);

	for (int i = 0; i < IDEAS_SIZE; i++)
		this->ideas[i].assign(br.ideas[i]);

	return (*this);
}

Brain::Brain	( const Brain& br )
{
	print_line("Brain- Copy Constructor", BOLDGREEN);
	*this = br;
}

Brain::Brain()
{
	print_line("Brain- Default Constructor", BOLDGREEN);
	for (int i = 0; i < IDEAS_SIZE; i++)
		this->ideas[i].assign("un-initialized");
}

Brain::~Brain()
{
	print_line("<<Brain Destroyed>>", BOLDRED);
}

const std::string&	Brain::get_idea( size_t idx ) const
{
	if (idx < 0 || idx > IDEAS_SIZE - 1)
		return (this->ideas[IDEAS_SIZE - 1]);
	else
		return (this->ideas[idx]);
}

void	Brain::set_idea( std::string idea, size_t idx )
{
	if ( 0 <= idx && idx < IDEAS_SIZE)
		this->ideas[idx].assign(idea);
}
