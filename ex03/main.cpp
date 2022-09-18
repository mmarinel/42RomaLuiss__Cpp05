/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 20:05:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main( void )
{
	{
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter*	me = new Character("me");
		AMateria*	tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter*	bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete tmp;
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << std::endl;

		IMateriaSource*	src = new MateriaSource();
		ICharacter*		me = new Character("Matteo");
		ICharacter*		boredom = new Character("Boredom");
		AMateria*		tmp;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;

		std::cout << std::endl << BOLDWHITE 
		<< "Attacking Boredom" << RESET
			<< std::endl;
		me->use(1, *boredom);

		std::cout << std::endl << BOLDWHITE
			<< "Cloning myself...then deleting all materias from the copy" << RESET
			<< std::endl;
		Character	clone = *dynamic_cast<Character *>(me);
		clone.unequip(0);
		clone.unequip(1);
		clone.unequip(2);
		clone.unequip(3);
		std::cout << CYAN << "me: " << RESET; me->use(1, *boredom);
		std::cout << CYAN << "clone: " << RESET; clone.use(1, *boredom);

		std::cout << std::endl << BOLDWHITE
			<< "overwriting original with copy...must have no leaks!" << RESET
			<< std::endl;
		*me = clone;

		std::cout << std::endl;
		delete me;
		delete boredom;
		delete src;
	}
	return 0;
}
