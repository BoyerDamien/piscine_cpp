/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:36:07 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 14:39:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RadScorpion.hpp"
#include "Enemy.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "Rad Scorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &other) : Enemy(other)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion &RadScorpion::operator=(const RadScorpion &other)
{
	this->setHP(other.getHP());
	this->setType(other.getType());
	return *this;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
}
