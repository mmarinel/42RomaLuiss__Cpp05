/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:33:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/14 18:29:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# define IDEAS_SIZE 100

# include <string>
# include <iostream>
# include "utils.hpp"

class Brain
{
private:
	std::string					ideas[IDEAS_SIZE];
public:
			const	Brain&			operator	= 	( const Brain& br );
									Brain			( const Brain& br );
									Brain			();
	virtual							~Brain			();
			const	std::string&	get_idea		( size_t idx ) const;
					void			set_idea		( std::string idea, size_t idx );
};


#endif /* BRAIN_H */