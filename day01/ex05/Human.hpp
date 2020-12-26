/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:39:25 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:20:43 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "./Brain.hpp"
#include <iostream>

class Human
{

  private:
	const Brain _brain;

  public:
	Human(void);
	~Human();
	Brain const &getBrain(void) const;
	void *identify(void) const;
};

#endif
