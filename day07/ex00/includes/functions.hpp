/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:31:09 by root              #+#    #+#             */
/*   Updated: 2021/01/16 14:37:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace My
{
template <typename T> T const &max(T const &s1, T const &s2)
{
	return s1 > s2 ? s1 : s2;
}

template <typename T> T const &min(T const &s1, T const &s2)
{
	return s1 < s2 ? s1 : s2;
}

template <typename T> void swap(T &s1, T &s2)
{
	T tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}
} // namespace My

#endif
