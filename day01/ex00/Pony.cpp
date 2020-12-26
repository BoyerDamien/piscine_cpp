/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:42:10 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:19:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
	std::cout << "The pony " << name << " was created " << std::endl;
}

Pony::~Pony()
{
	std::cout << "The pony " << this->_name << " was destroyed " << std::endl;
}

void Pony::announce(void) const
{
	std::cout << "Hello i'm the pony " << this->_name << std::endl;
}
