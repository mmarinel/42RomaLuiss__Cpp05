/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:37:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/19 10:15:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

# define safe_delete(ptr) {delete ptr; ptr = nullptr;}

# include "../colors.hpp"
# include <iostream>

	//* utils

void	print_line(const char *str, const char *color);
void	print_funcName(const char *funcName);

#endif /* COMMON_UTILS_H */