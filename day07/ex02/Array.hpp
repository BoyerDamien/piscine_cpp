/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:19:02 by root              #+#    #+#             */
/*   Updated: 2021/01/16 15:46:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

namespace My
{
template <typename T = float> class Array
{
  public:
	/******************************************************************************
	 * 				Constructors
	 *****************************************************************************/

	Array(void) : _content(NULL), _len(0){};
	Array(unsigned int n) : _content(new T[n]), _len(n){};
	Array(Array const &other) : _content(other.clone()), _len(other.lenght()){};
	Array &operator=(Array const &other)
	{
		this->_content = other.clone();
		this->_len = other.lenght();
		return *this;
	}
	~Array(void){
		delete this->_content;
	};

	/******************************************************************************
	 * 				Getters
	 *****************************************************************************/
	T *getContent(void) const
	{
		return this->_content;
	}

	size_t lenght(void) const
	{
		return this->_len;
	}

	/****************************************************************************
	 *				Member functions
	 ****************************************************************************/
	T *clone(void) const
	{
		T *_new = new Array<T>(this->_len);
		for (size_t i = 0; i < this->_len; i++)
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
	size_t _len;
};

} // namespace My
#endif
