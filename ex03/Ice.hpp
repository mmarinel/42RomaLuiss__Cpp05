/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:44:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 10:50:40 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "types.hpp"
# include "AMateria.hpp"

# include <string>
# include <iostream>

class Ice : public AMateria
{
private:
	/**/
public:
	virtual void		use( ICharacter& target );
	virtual AMateria	*clone( void ) const;
	const Ice&			operator = ( const Ice& to_copy );
						Ice	( const Ice& to_copy );
						Ice();
						~Ice();
};


#endif /* ICE_H */