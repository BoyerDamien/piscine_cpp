/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:23:05 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:20:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain(void)
{
	std::cout << "A brain was created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "A brain was destroyed" << std::endl;
}

void *Brain::identify(void) const
{
	return (void *)this;
}
