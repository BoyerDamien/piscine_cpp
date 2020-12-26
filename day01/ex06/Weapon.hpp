/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:43:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:21:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{

  private:
	std::string _type;

  public:
	Weapon(const std::string);
	~Weapon();
	const std::string &getType(void) const;
	void setType(const std::string);
};

#endif
