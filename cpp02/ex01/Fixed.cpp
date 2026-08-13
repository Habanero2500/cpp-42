/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:43:31 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/08 15:52:07 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int nbr )
{
    std::cout << "Int constructor called" << std::endl;
    _nbr = nbr << _numberBits; 
}

Fixed::Fixed( float nbr )
{
    _nbr = roundf(nbr * (1 << _numberBits)); // convert a float to int
    std::cout << "Float constructor called" << std::endl;
    
}
Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
    std::cout << "Copy constructor called" << std::endl;
    this->_nbr = copy.getRawBits();
}
int Fixed::getRawBits( void ) const
{
    return (this->_nbr);
}

void Fixed::setRawBits(int const nbr)
{
    this->_nbr = nbr;
}
float Fixed::toFloat(void) const
{
	return (float)_nbr / (1 << _numberBits);
}

int Fixed::toInt(void) const
{
	return _nbr >> _numberBits;
}

Fixed & Fixed::operator=( Fixed const & other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    this-> _nbr = other.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

