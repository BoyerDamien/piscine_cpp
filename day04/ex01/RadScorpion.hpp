/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:31:20 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/04 15:26:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_H
#define RADSCORPION_H

#include "./Enemy.hpp"

class RadScorpion : public Enemy
{
  private:
	RadScorpion(std::string const &);

  public:
	RadScorpion(void);
	RadScorpion(RadScorpion const &);
	RadScorpion &operator=(RadScorpion const &);
	virtual ~RadScorpion(void);
};

#endif
