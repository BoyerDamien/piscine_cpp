/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:18:46 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:20:33 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

  public:
	Brain(void);
	~Brain();
	void *identify(void) const;
};

#endif
