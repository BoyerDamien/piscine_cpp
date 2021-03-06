/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:14:15 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 15:34:11 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_H
#define PEON_H

#include "./Victim.hpp"

class Peon : public Victim
{
	// Canonical form
  private:
	Peon(void); // Private default constructor

  public:
	Peon(std::string);
	Peon(Peon const &);
	Peon &operator=(Peon const &);
	virtual ~Peon(void);

	// Methods override
	void getPolymorphed(void) const;
};

bool operator==(Peon const &, Peon const &);

#endif
