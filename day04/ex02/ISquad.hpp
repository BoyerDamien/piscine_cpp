/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:30:02 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:28:10 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_H
#define ISQUAD_H
#include "./ISpaceMarine.hpp"

class ISquad
{
  public:
	virtual ~ISquad(){};
	virtual int getCount() const = 0;
	virtual ISpaceMarine *getUnit(int) const = 0;
	virtual int push(ISpaceMarine *) = 0;
};

#endif
