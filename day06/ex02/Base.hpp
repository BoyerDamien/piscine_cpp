/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:57:36 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 10:25:58 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
  public:
	Base(void);
	Base(Base const &);
	Base &operator=(Base const &);
	virtual ~Base(void);
};

#endif
