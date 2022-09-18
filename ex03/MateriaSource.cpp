/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:49:40 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 11:23:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i;

	for (i = MS_MATERIAS - 1; i >= 0; i--)
		if (nullptr != this->materias[i]
			&& 0 == this->materias[i]->getType().compare(type))
			break ;

	if (i == -1)
		return (0);
	else
		return this->materias[i]->clone();
}

void	MateriaSource::learnMateria( AMateria* materia )
{
	size_t	i;

	if (nullptr != materia)
	{
		for (i = 0; i < MS_MATERIAS; i++)
			if (nullptr == this->materias[i])
				break;

		if (i < MS_MATERIAS)
		{
			this->materias[i] = materia->clone();
		}
		delete materia;
	}
}

const MateriaSource&	MateriaSource::operator =	( const MateriaSource& to_copy )
{
	print_line("MateriaSource- Copy Assignment Operator", YELLOW);

	delete_materias();
	for (size_t i = 0; i < MS_MATERIAS; i++)
		if (nullptr == to_copy.materias[i])
			this->materias[i] = nullptr;
		else
			this->materias[i] = to_copy.materias[i]->clone();

	return (*this);
}

MateriaSource::MateriaSource( const MateriaSource& to_copy)
{
	print_line("MateriaSource- Copy Constructor", BOLDGREEN);

	*this = to_copy;
}

MateriaSource::MateriaSource()
{
	print_line("MateriaSource- Default Constructor", BOLDGREEN);

	for (size_t i = 0; i < MS_MATERIAS; i++)
		this->materias[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	delete_materias();

	print_line("<<MateriaSource Destroyed>>", BOLDRED);
}

void	MateriaSource::delete_materias( void )
{
	for (size_t i = 0; i < MS_MATERIAS; i++)
		if (nullptr != this->materias[i])
			delete this->materias[i];
}
