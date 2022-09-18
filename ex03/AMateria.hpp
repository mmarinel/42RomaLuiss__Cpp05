/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:09:28 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 10:50:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include "types.hpp"
# include "ICharacter.hpp"
# include "utils.hpp"

# include <string>
# include <iostream>

class AMateria
{
protected:
	const std::string	type;
public:
			std::string const &	getType() const;//* Returns the materia type
	virtual	void				use			( ICharacter& target );
	virtual	AMateria*			clone() const = 0;
	const	AMateria&			operator =	( const AMateria& to_copy );
								AMateria	( AMateria const & to_copy );
								AMateria	( std::string const & type );
								AMateria	();
	virtual						~AMateria	();
};


#endif /* AMATERIA_H */