/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:39:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/20 10:08:58 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	print_line(const char *str, const char *color)
{
	std::cout << color
		<< str
		<< RESET
		<< std::endl;
}

void	print_funcName(const char *funcName)
{
	std::cout
		<< YELLOW
		<< "in " << funcName << ": "
		<< RESET;
}

char	*str_concat(const char *s1, const char *s2)
{
	char	s_cat[std::strlen(s1) + std::strlen(s2) + 1];

	std::memset(s_cat, '\000', std::strlen(s1) + std::strlen(s2) + 1);
	std::strcat(s_cat, s1);
	std::strcat(s_cat, s2);
}
