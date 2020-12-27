/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:48:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/27 11:48:18 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{

  public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed &operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(const int raw);

  private:
	int _value;
	static const int _n_bits = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif
