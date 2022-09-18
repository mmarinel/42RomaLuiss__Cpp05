/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:07:57 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/14 16:19:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

# include <string>
# include <iostream>

# include "Brain.hpp"
# include "Animal.hpp"
# include "utils.hpp"

class Cat : public Animal
{
private:
			Brain*	brain;
	mutable int		__next_idea;
public:
					void	makeSound	( void ) const;
					void	emptyMind	( void );
	virtual	const	Animal&	operator =	( const Animal& to_copy );
	virtual	const	Cat&	operator =	( const Cat& to_copy );
							Cat			( const Cat& to_copy );
							Cat			();
							~Cat		();
};


#endif /* CAT_H */
