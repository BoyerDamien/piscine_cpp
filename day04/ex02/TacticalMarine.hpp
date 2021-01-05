/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:41:09 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:24:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_H
#define TACTICALMARINE_H

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine
{
  public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const &);
	TacticalMarine &operator=(TacticalMarine const &);
	virtual ~TacticalMarine();

	// Methods
	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
