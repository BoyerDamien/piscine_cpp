/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:08:03 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/17 10:27:13 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"
#include <algorithm>
#include <iostream>

/******************************************************************************
 *				Constructors
 *****************************************************************************/
Span::Span(unsigned int N) : _n(N)
{
}

Span::Span(Span const &other) : _content(std::vector<int>(other.getContent()))
{
}

Span &Span::operator=(const Span &other)
{
	this->_content = std::vector<int>(other.getContent());
	this->_n = other.getN();
	return *this;
}

Span::~Span()
{
}

/******************************************************************************
 *				Getters
 *****************************************************************************/
std::vector<int> Span::getContent() const
{
	return this->_content;
}

unsigned int Span::getN() const
{
	return this->_n;
}

std::vector<int>::iterator Span::end()
{
	return this->_content.end();
}
std::vector<int>::iterator Span::begin()
{
	return this->_content.begin();
}

/******************************************************************************
 *				Member functions
 *****************************************************************************/
void Span::addNumber(int number) throw(Span::ContainerFullException)
{
	if (this->_content.size() >= this->_n)
	{
		throw(Span::ContainerFullException());
	}
	this->_content.push_back(number);
}

void Span::addNumber(
	std::vector<int>::iterator position, std::vector<int>::iterator otherBegin,
	std::vector<int>::iterator otherEnd) throw(Span::ContainerFullException)
{
	if (this->_content.size() >= this->_n)
	{
		throw(Span::ContainerFullException());
	}
	this->_content.insert(position, otherBegin, otherEnd);
}

void Span::addNumber(std::vector<int>::iterator position, int *otherBegin,
					 int *otherEnd) throw(Span::ContainerFullException)
{
	if (this->_content.size() >= this->_n)
	{
		throw(Span::ContainerFullException());
	}
	this->_content.insert(position, otherBegin, otherEnd);
}

int Span::longestSpan(void) const throw(Span::NoSpanToFindException)
{
	if (this->_content.size() <= 1)
	{
		throw(Span::NoSpanToFindException());
	}
	std::vector<int> clone = std::vector<int>(this->_content);
	std::sort(clone.begin(), clone.end());
	return *(clone.end() - 1) - *clone.begin();
}

int Span::shortestSpan(void) const throw(Span::NoSpanToFindException)
{
	if (this->_content.size() <= 1)
	{
		throw(Span::NoSpanToFindException());
	}
	std::vector<int> clone = std::vector<int>(this->_content);
	std::sort(clone.begin(), clone.end());
	return clone[1] - clone[0];
}

/******************************************************************************
 *				Exceptions
 *****************************************************************************/
const char *Span::ContainerFullException::what() const throw()
{
	return "Container full";
}

const char *Span::NoSpanToFindException::what() const throw()
{
	return "No span to find";
}
