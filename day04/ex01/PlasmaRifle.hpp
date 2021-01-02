/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:39:12 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 18:40:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include "./AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
  private:
	PlasmaRifle(void);

  public:
	PlasmaRifle(std::string const &, int, int);
	PlasmaRifle(PlasmaRifle const &);
	PlasmaRifle &operator=(PlasmaRifle const &);
	~PlasmaRifle(void);

	// Methods
	void attack(void) const;
};

#endif
