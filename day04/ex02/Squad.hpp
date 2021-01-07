/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:36:24 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 10:45:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
#define SQUAD_H

#include "./ISpaceMarine.hpp"
#include "./ISquad.hpp"
#include <iostream>
#include <ostream>

class Squad : public ISquad
{
  private:
	int _n;
	ISpaceMarine **_content;

	void _cleanSquad(void);

  public:
	// Canonical form
	Squad();
	Squad(Squad const &);
	Squad &operator=(Squad const &);
	virtual ~Squad();

	// Methods
	int getCount() const;
	ISpaceMarine *getUnit(int) const;
	ISpaceMarine **getContent() const;
	int push(ISpaceMarine *);
};

std::ostream &operator<<(std::ostream &, ISquad const *);
#endif
