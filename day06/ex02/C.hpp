/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:57:36 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:27:51 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
#define C_H
#include "Base.hpp"

class C : public Base
{
  public:
	C(void);
	C(C const &);
	C &operator=(C const &);
	virtual ~C(void);
};

#endif
