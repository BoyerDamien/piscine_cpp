/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 19:00:33 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 09:17:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

class Enemy
{
  private:
	std::string _type;
	int _hp;

	Enemy(void);

  public:
	// Constructors
	Enemy(int, std::string const &);
	Enemy(Enemy const &);
	Enemy &operator=(Enemy const &);
	virtual ~Enemy(void);

	// Getters
	std::string getType(void) const;
	int getHP(void) const;

	// Setters
	void setHP(int);
	void setType(std::string const &);

	// Methods
	virtual void takeDamage(int);
};

bool operator==(Enemy const &, Enemy const &);
#endif
