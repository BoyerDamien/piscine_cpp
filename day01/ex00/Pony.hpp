/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:42:29 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:19:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Pony
{

  private:
	std::string _name;

  public:
	Pony(std::string name);
	~Pony();
	void announce(void) const;
};
