/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:39:12 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/06 15:44:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include "./AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
  public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &);
	PlasmaRifle &operator=(PlasmaRifle const &);
	virtual ~PlasmaRifle(void);

	// Methods
	void attack(void) const;
};

#endif
