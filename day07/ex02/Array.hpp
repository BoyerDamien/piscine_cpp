/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:19:02 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 16:58:33 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H
#include <exception>
#include <iostream>
#include <ostream>

namespace My
{

/****************************************************************************
 *		Exception
 ****************************************************************************/
class MemoryAccessException : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Unauthorized memory access";
	}
};

template <typename T = float> class Array
{
  public:
	/******************************************************************************
	 * 				Constructors
	 *****************************************************************************/

	Array<T>(void) : _content(NULL), _size(0){};

	Array<T>(unsigned int n) : _content(new T[n]), _size(n){};

	Array<T>(Array const &other)
		: _content(other.clone()), _size(other.size()){};

	Array<T> &operator=(Array const &other)
	{
		if (this->_content)
		{
			delete[] this->_content;
		}
		this->_content = other.clone();
		this->_size = other.size();
		return *this;
	}

	T &operator[](int idx) const throw(My::MemoryAccessException)
	{
		if (idx >= this->_size || idx < 0 || !this->_content)
		{
			throw(My::MemoryAccessException());
		}
		return this->_content[idx];
	}

	virtual ~Array(void)
	{
		if (this->_content)
			delete[] this->_content;
	};

	/******************************************************************************
	 * 				Getters
	 *****************************************************************************/
	T *getContent(void) const
	{
		return this->_content;
	}

	int size(void) const
	{
		return this->_size;
	}
	/****************************************************************************
	 *				Member functions
	 ****************************************************************************/
	T *clone(void) const
	{
		T *_new = new My::Array<T>(this->_size);
		for (int i = 0; i < this->_size; i++)
		{
			_new[i] = this->_content[i];
		}
		return _new;
	}

  private:
	/******************************************************************************
	 * 				Attributes
	 *****************************************************************************/
	T *_content;
	int _size;
};

} // namespace My

template <typename T>
std::ostream &operator<<(std::ostream &os, My::Array<T> const &arr)
{
	os << "[ ";
	for (int i = 0; i < arr.size(); i++)
	{
		os << arr[i] << " ";
	}
	return os << "]";
}
#endif
