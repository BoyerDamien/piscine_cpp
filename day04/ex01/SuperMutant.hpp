/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:13:02 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 14:30:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "./Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy
{
  private:
	SuperMutant(std::string const &);

  public:
	SuperMutant(void);
	SuperMutant(SuperMutant const &);
	SuperMutant &operator=(SuperMutant const &);
	virtual ~SuperMutant(void);

	// Methods
	void takeDamage(int);
};

#endif
