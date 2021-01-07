/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:23:14 by dboyer            #+#    #+#             */
/*   Updated: 2021/01/07 12:20:33 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "./IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
  private:
	AMateria **_materias;
	void _cleanMaterias(void);

  public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &);
	MateriaSource &operator=(MateriaSource const &);
	virtual ~MateriaSource(void);

	// Methods
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
	// Getters
	AMateria **getMaterias() const;
};

bool operator==(MateriaSource const &, MateriaSource const &);
#endif
