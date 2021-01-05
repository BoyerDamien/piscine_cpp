/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:46:50 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 14:27:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
#define POWERFIST_H

#include "./AWeapon.hpp"

class PowerFist : public AWeapon
{
  private:
	PowerFist(std::string const &);

  public:
	PowerFist(void);
	PowerFist(PowerFist const &);
	PowerFist &operator=(PowerFist const &);
	virtual ~PowerFist(void);

	void attack(void) const;
};

#endif
