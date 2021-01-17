/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 08:25:57 by root              #+#    #+#             */
/*   Updated: 2021/01/17 08:56:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>

class NotFoundException : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Not found";
	}
};

template <typename Container>
int easyfind(Container &container, int const occ) throw(NotFoundException)
{
	typename Container::iterator iter =
		std::find(container.begin(), container.end(), occ);
	if (iter != container.end())
	{
		return *iter;
	}
	throw(NotFoundException());
}

#endif
