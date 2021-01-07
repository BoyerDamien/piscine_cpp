/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:37:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 12:40:11 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "./ICharacter.hpp"

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria **_materias;
	Character(void);

  public:
	Character(std::string const &);
	Character(Character const &);
	Character &operator=(Character const &);
	virtual ~Character();

	// Methods
	void equip(AMateria *);
	void unequip(int);
	void use(int, ICharacter &);

	// Getters
	std::string const &getName() const;
	AMateria **getMaterias() const;
};

bool operator==(Character const &, Character const &);
#endif
