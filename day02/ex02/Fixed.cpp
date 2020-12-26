/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:56:40 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 09:38:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <cmath>

/******************************************************************************
 *				Méthodes
 ******************************************************************************/
Fixed::Fixed(void) : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << this->_n_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(value) {
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(value * (1 << this->_n_bits));
}

Fixed::Fixed(Fixed const &src) : _value(src.getRawBits()) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}

void Fixed::setRawBits(int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_value = raw;
}

float Fixed::toFloat(void) const {
  return (float)this->_value / (1 << this->_n_bits);
}

int Fixed::toInt(void) const { return this->_value >> this->_n_bits; }

/*****************************************************************************************
 * 					Operator overloading
 * ***************************************************************************************/

Fixed &Fixed::operator=(Fixed const &src) {
  std::cout << "Assignation operator called" << std::endl;
  this->_value = src.getRawBits();
  return *this;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &n) {
  return stream << n.toFloat();
}

bool Fixed::operator==(const Fixed &r) const {
  return this->toFloat() == r.toFloat();
}

bool Fixed::operator>=(const Fixed &r) const {
  return this->toFloat() >= r.toFloat();
}

bool Fixed::operator<=(const Fixed &r) const {
  return this->toFloat() <= r.toFloat();
}

bool Fixed::operator>(const Fixed &r) const {
  return this->toFloat() > r.toFloat();
}

bool Fixed::operator<(const Fixed &r) const {
  return this->toFloat() < r.toFloat();
}

bool Fixed::operator!=(const Fixed &r) const {
  return this->toFloat() != r.toFloat();
}

Fixed Fixed::operator+(const Fixed &r) const {
  return Fixed(this->toFloat() + r.toFloat());
}

Fixed Fixed::operator-(const Fixed &r) const {
  return Fixed(this->toFloat() - r.toFloat());
}

Fixed Fixed::operator*(const Fixed &r) const {
  return Fixed(this->toFloat() * r.toFloat());
}

Fixed Fixed::operator/(const Fixed &r) const {
  return Fixed(this->toFloat() / r.toFloat());
}

// Pre-increment
Fixed &Fixed::operator++(void) {
  this->_value++;
  return *this;
}

// Pre-decrement
Fixed &Fixed::operator--(void) {
  this->_value--;
  return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->operator++();
  return tmp;
}
// Post-decrement
Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->operator--();
  return tmp;
}

/*****************************************************************
 * 			No member functions
 *****************************************************************/

const Fixed &Fixed::max(const Fixed &l, const Fixed &r) {
  return l < r ? r : l;
}

const Fixed &Fixed::min(const Fixed &l, const Fixed &r) {
  return l < r ? l : r;
}
