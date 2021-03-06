/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:25:50 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/24 13:25:53 by dboyer           ###   ########.fr       */
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
