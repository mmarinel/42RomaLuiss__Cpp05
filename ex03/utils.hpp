/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:37:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 11:08:20 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../colors.hpp"
# include <string>
# include <iostream>

	//* utils

typedef struct s_list
{
	void			*content;
	bool			del_content;
	void			(*del_cont)(void *content);
	struct s_list	*tail;
	struct s_list	*next;
	void			add_back( void *content, bool del_content );
					s_list( void *content, bool del_content, void (*del_cont)(void *content) );
					~s_list();
}	t_list;

void	print_line(const std::string& str, const char *color);//* Coercion Polymorphism happens here if we pass const char*
void	print_funcName(const std::string& funcName);


#endif /* COMMON_UTILS_H */
