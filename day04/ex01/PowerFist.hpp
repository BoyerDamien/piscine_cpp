/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:46:50 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/02 18:51:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
#define POWERFIST_H

#include "./AWeapon.hpp"

class PowerFist : public AWeapon
{
  private:
	PowerFist(void);

  public:
	PowerFist(std::string const &, int, int);
	PowerFist(PowerFist const &);
	PowerFist &operator=(PowerFist const &);
	~PowerFist(void);

	void attack(void) const;
};

#endif
