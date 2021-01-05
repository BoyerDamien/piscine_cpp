/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:56:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 15:12:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include "./ICharacter.hpp"
#include <iostream>

class AMateria
{
  private:
	unsigned int _xp;
	std::string _type;

  public:
	AMateria(void);
	AMateria(AMateria const &);
	AMateria(std::string const &type);
	~AMateria();

	// Methods
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
