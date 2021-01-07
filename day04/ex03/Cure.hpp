/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:21:56 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 10:29:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "./AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
  private:
	Cure(std::string const &);

  public:
	Cure(void);
	Cure(Cure const &);
	Cure &operator=(AMateria const &);
	virtual ~Cure();

	void use(ICharacter &target);
	AMateria *clone() const;
};

#endif
