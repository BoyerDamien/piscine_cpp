/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:41:38 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 15:17:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <ostream>

class Character
{
  private:
	// Attributes
	std::string _name;
	AWeapon *_weapon;
	int _AP;

	// Default constructor
	Character(void);

  public:
	Character(std::string const &);
	Character(Character const &);
	Character &operator=(Character const &);
	~Character(void);

	// Methods
	void recoveryAP(void);
	void equip(AWeapon *);
	void attack(Enemy *);

	// Getters
	std::string getName(void) const;
	AWeapon *getWeapon(void) const;
	int getAP(void) const;
};

std::ostream &operator<<(std::ostream &, Character const &);

#endif
