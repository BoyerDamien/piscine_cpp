/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:54:31 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 10:20:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &other) : AMateria(other)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(AMateria const &other)
{
	AMateria::operator=(other);
	return *this;
}

void Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << "*"
			  << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice();
}
