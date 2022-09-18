/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 09:46:15 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 10:51:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "types.hpp"
# include "IMateriaSource.hpp"
# include "utils.hpp"

# define MS_MATERIAS 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	materias[MS_MATERIAS];
	void		delete_materias( void );
public:
	virtual AMateria*		createMateria(std::string const & type);
	virtual void			learnMateria	(AMateria*);
	const MateriaSource&	operator =		( const MateriaSource& to_copy );
							MateriaSource	( const MateriaSource& to_copy );
							MateriaSource	();
							~MateriaSource	();
};


#endif /* MATERIASOURCE_H */
