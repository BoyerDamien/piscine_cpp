/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:48:12 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:22:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{

  public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(Fixed const &src);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;

	// Operator overloading
	Fixed &operator=(Fixed const &);
	bool operator==(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator>(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator!=(const Fixed &) const;
	Fixed operator+(const Fixed &) const;
	Fixed operator-(const Fixed &) const;
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static const Fixed &max(const Fixed &, const Fixed &);
	static const Fixed &min(const Fixed &, const Fixed &);

  private:
	int _value;
	static const int _n_bits = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);
