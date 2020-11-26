/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:42:19 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 10:26:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Human.hpp"

Human::Human(void) {
  std::cout << "A human with the brain " << this->_brain.identify()
            << " was created" << std::endl;
}

Human::~Human() {
  std::cout << "A human with the brain " << this->_brain.identify()
            << " was destroyed" << std::endl;
}

Brain const &Human::getBrain(void) const { return this->_brain; }

void *Human::identify(void) const { return this->_brain.identify(); }
