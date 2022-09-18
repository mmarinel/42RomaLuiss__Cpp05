/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:59:26 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 10:31:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

# include <string>
# include <iostream>

# include "Brain.hpp"
# include "Animal.hpp"
# include "utils.hpp"

class Dog : public Animal
{
private:
			Brain*	brain;
	mutable int		__next_idea;
public:
							void			makeSound				( void ) const;
			const			std::string&	oneVeryImportantThought	( void ) const;
							void			emptyMind				( void );
	virtual	const			Animal&			operator =				( const Animal& to_copy );
	virtual	const			Dog&			operator =				( const Dog& to_copy );
											Dog						( const Dog& to_copy );
											Dog						();
											~Dog					();
};


#endif /* DOG_H */
