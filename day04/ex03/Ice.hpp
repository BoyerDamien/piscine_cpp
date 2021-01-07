/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:51:06 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 10:21:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "./AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
  private:
	Ice(std::string const &);

  public:
	Ice(void);
	Ice(Ice const &);
	Ice &operator=(AMateria const &);
	virtual ~Ice();

	// Methods
	void use(ICharacter &);
	AMateria *clone() const;
};

#endif
