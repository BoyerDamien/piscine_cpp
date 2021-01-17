/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:19:43 by root              #+#    #+#             */
/*   Updated: 2021/01/17 12:51:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_H
#define MUTANSTACK_H

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	MutantStack<T>(void) : std::stack<T>(){};
	MutantStack<T>(MutantStack<T> const &other) : std::stack<T>(other){};
	using std::stack<T>::operator=;
	~MutantStack<T>(void){};

	typedef typename std::deque<T>::iterator iterator;

	iterator begin(void)
	{
		return this->c.begin();
	};
	iterator end(void)
	{
		return this->c.end();
	}
};

#endif
