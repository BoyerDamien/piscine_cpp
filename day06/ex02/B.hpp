/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:57:36 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:15:28 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_H
#define B_H
#include "Base.hpp"

class B : public Base
{
  public:
	B(void);
	B(B const &);
	B &operator=(B const &);
	virtual ~B(void);
};

#endif
