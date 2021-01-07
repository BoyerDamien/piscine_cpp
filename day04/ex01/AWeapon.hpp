/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:59:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 15:45:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWeapon_H
#define AWeapon_H

#include <iostream>

class AWeapon
{
  private:
	std::string _name;
	int _apcost;
	int _damage;

	AWeapon(void); // Private default constructor

  public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &);
	virtual ~AWeapon();

	AWeapon &operator=(AWeapon const &);

	// Getters
	std::string getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;

	// Setters
	void setName(std::string);
	void setAPCost(int);
	void setDamage(int);

	// Methods
	virtual void attack(void) const = 0;
};

bool operator==(AWeapon const &, AWeapon const &);
#endif
