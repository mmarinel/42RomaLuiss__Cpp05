/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt1.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:39:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/09/16 11:10:01 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	s_list::add_back( void *content, bool del_content )
{
	this->tail->next = new t_list(content, del_content, this->del_cont);
	this->tail = this->tail->next;
}

s_list::s_list( void *content, bool del_content, void (*del_cont)(void *content) )
{
	this->content = content;
	this->del_content = del_content;
	this->del_cont = del_cont;
	this->tail = this;
	this->next = nullptr;
}

s_list::~s_list()
{
	if (true == this->del_content)
		this->del_cont(this->content);
	if (nullptr != this->next)
		delete this->next;
}

void	print_line(const std::string& str, const char *color)
{
	std::cout << color
		<< str
		<< RESET
		<< std::endl;
}

void	print_funcName(const std::string& funcName)
{
	std::cout
		<< YELLOW
		<< "in " << funcName << ": "
		<< RESET;
}
