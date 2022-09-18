/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:44:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/15 15:31:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "types.hpp"
# include "AMateria.hpp"

# include <string>
# include <iostream>

class Cure : public AMateria
{
private:
	/**/
public:
	virtual void		use( ICharacter& target );
	virtual AMateria	*clone( void ) const;
	const Cure&			operator = ( const Cure& to_copy );
						Cure	( const Cure& to_copy );
						Cure();
						~Cure();
};


#endif /* Cure_H */