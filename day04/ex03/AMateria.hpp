/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:56:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 14:51:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>

class ICharacter;

class AMateria
{
  private:
	unsigned int _xp;
	std::string _type;
	AMateria(void);

  public:
	AMateria(std::string const &type);
	AMateria(AMateria const &);
	AMateria &operator=(AMateria const &);
	virtual ~AMateria();

	// Methods
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

	// Getters
	std::string const &getType() const;
	int getXP() const;
};

#endif
