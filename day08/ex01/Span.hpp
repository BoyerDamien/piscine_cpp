/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:03:39 by root              #+#    #+#             */
/*   Updated: 2021/01/17 10:15:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span
{
  private:
	std::vector<int> _content;
	unsigned int _n;
	Span(void); // Private default constructor

  public:
	Span(unsigned int);
	Span(Span const &);
	Span &operator=(Span const &);
	virtual ~Span(void);

	// Member functions
	int shortestSpan(void) const throw(Span::NoSpanToFindException);
	int longestSpan(void) const throw(Span::NoSpanToFindException);
	void addNumber(int) throw(Span::ContainerFullException);
	void addNumber(std::vector<int>::iterator, int *,
				   int *) throw(Span::ContainerFullException);
	void addNumber(
		std::vector<int>::iterator, std::vector<int>::iterator,
		std::vector<int>::iterator) throw(Span::ContainerFullException);

	// Getters
	std::vector<int> getContent(void) const;
	unsigned int getN(void) const;
	std::vector<int>::iterator end();
	std::vector<int>::iterator begin();

	// Exceptions
	class ContainerFullException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

	class NoSpanToFindException : public std::exception
	{
	  public:
		const char *what() const throw();
	};
};
#endif
