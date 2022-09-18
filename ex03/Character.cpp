/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:50:41 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/17 09:36:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

static void	del_AMateria(void* materia);
//* end of static declaration

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx <= MATERIAS - 1)
	{
		if (nullptr != this->materias[idx])
			this->materias[idx]->use(target);
		else
			print_line("Unequipped Materia!", CYAN);
	}
}

void	Character::equip( AMateria* m )
{
	size_t	i;

	if (nullptr != m)
	{
		for (i = 0; i < MATERIAS; i++)
			if (nullptr == this->materias[i])
				break ;

		if (i < MATERIAS)
		{
			this->materias[i] = m->clone();
		}
	}
}

void	Character::unequip( int idx )
{
	if (0 <= idx && idx <= MATERIAS - 1
		&& nullptr != this->materias[idx])
	{
		if (nullptr == this->__garbage)
			this->__garbage = new t_list(this->materias[idx], true, del_AMateria);
		else
			this->__garbage->add_back(this->materias[idx], true);
		this->materias[idx] = nullptr;
	}
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-label"
const Character&	Character::operator =	( const Character& to_copy )
{
	print_line("Character- Copy Assignment Operator", YELLOW);

	garbage_collector();
	this->name.assign(to_copy.name);
	for (size_t i = 0; i < MATERIAS; i++)
	{
		del_previous: {
			if (nullptr != this->materias[i])
				delete this->materias[i];
		}
		if (nullptr == to_copy.materias[i])
			this->materias[i] = nullptr;
		else
			this->materias[i] = to_copy.materias[i]->clone();
	}

	return (*this);
}
#pragma GCC diagnostic pop

Character::Character( const Character& to_copy )
{
	print_line("Character- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

Character::Character( const std::string& name ) : name(name)
{
	print_line("Character- std::string Constructor", BOLDGREEN);

	this->__garbage = nullptr;
	for (size_t i = 0; i < MATERIAS; i++)
		this->materias[i] = nullptr;
}

Character::Character() : name("nameless")
{
	print_line("Character- Default Constructor", BOLDGREEN);

	this->__garbage = nullptr;
	for (size_t i = 0; i < MATERIAS; i++)
		this->materias[i] = nullptr;
}

Character::~Character()
{
	for (size_t i = 0; i < MATERIAS; i++)
		if (nullptr != this->materias[i])
			delete this->materias[i];
	garbage_collector();
	print_line("<<Character Destroyed>>", BOLDRED);
}

void	Character::garbage_collector( void )
{
	if (nullptr != this->__garbage)
		delete this->__garbage;
	this->__garbage = nullptr;
}

const std::string&	Character::getName( void ) const
{
	return (this->name);
}

static void	del_AMateria(void* materia)
{
	AMateria*	as_materia = static_cast<AMateria*>(materia);

	if (nullptr != as_materia)
		delete as_materia;
}
