/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:57:36 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:23:10 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_H
#define A_H
#include "Base.hpp"

class A : public Base
{
  public:
	A(void);
	A(A const &);
	A &operator=(A const &);
	virtual ~A(void);
};

#endif
