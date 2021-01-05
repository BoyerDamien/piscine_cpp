/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:39:12 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 14:26:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include "./AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
  private:
	PlasmaRifle(std::string const &);

  public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &);
	PlasmaRifle &operator=(PlasmaRifle const &);
	virtual ~PlasmaRifle(void);

	// Methods
	void attack(void) const;
};

#endif
