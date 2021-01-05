/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:53:55 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/05 12:20:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_H
#define ASSAULTTERMINATOR_H

#include "./ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine
{
  public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const &);
	AssaultTerminator &operator=(AssaultTerminator const &);
	virtual ~AssaultTerminator();

	// Methods
	ISpaceMarine *clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
#endif
