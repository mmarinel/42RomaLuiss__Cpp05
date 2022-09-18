/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:44:14 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 11:26:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

# define ANIMALS 4

static int	first_dog_occurence(Animal *animals[ANIMALS]);
//* end of static declarations

int	main()
{
	Animal	*animals[ANIMALS];
	Dog		copy;
	int		first_dog_occ;

	for (size_t i = 0; i < ANIMALS; i++)
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

//*********** Printing Animals ******************* //
//*********************************************** //
//*********************************************** //
	for (size_t i = 0; i < ANIMALS; i++)
	{
		std::cout << YELLOW
			<< "Animal " << i << " is a " << animals[i]->getType()
			<< ": " << RESET;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

//*********** Checking Deep Copy ******************* //
//*********************************************** //
//*********************************************** //

	first_dog_occ = first_dog_occurence(animals);
	if (-1 != first_dog_occ)
	{
		copy = *animals[first_dog_occ];
		std::cout
			<< std::endl
			<< CYAN
			<< "Checking correctness of Deep Copy"
			<< RESET;

		//* 	Original Values ******************//
		// ************************************** //
		// ************************************** //
		std::cout << std::endl;
		std::cout
			<< "Orginal animal:-> One Very Important Thought: "
			<< YELLOW
			<< dynamic_cast<Dog *>(
				animals[first_dog_occ]
				)->oneVeryImportantThought()
			<< std::endl
			<< RESET;
		std::cout
			<< "Copy animal:-> One Very Important Thought: "
			<< YELLOW
			<< copy.oneVeryImportantThought()
			<< RESET
			<< std::endl;
		std::cout << std::endl;

		std::cout
			<< CYAN
			<< "Modifying the copy"
			<< RESET;
		copy.emptyMind();

		//* 	Modified Values ******************//
		// ************************************** //
		// ************************************** //
		std::cout << std::endl;
		std::cout
			<< "Orginal animal:-> One Very Important Thought: "
			<< YELLOW
			<< dynamic_cast<Dog *>(
				animals[first_dog_occ]
				)->oneVeryImportantThought()
			<< std::endl
			<< RESET;
		std::cout
			<< "Copy animal:-> One Very Important Thought: "
			<< YELLOW
			<< copy.oneVeryImportantThought()
			<< RESET
			<< std::endl;
		std::cout << std::endl;
	}

	for (size_t i = 0; i < ANIMALS; i++)
		delete animals[i];

	{
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		delete j;//*should not create a leak
		delete i;
	}
	std::cout << "main end" << std::endl;
	return 0;
}

static int	first_dog_occurence(Animal *animals[ANIMALS])
{
	Dog		*orig;
	size_t	i;

	i = 0;
	do
	{
		if (i > ANIMALS - 1)
			return (-1);
		orig = dynamic_cast<Dog *>(animals[i++]);
	} while (nullptr == orig);

	return (i - 1);
}
