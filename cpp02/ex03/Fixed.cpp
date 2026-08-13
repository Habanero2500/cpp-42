/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:28:21 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/09 12:55:55 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
    this->_nbr = 0;
}

Fixed::Fixed( int nbr )
{
    this->_nbr = nbr * (1 << _numberBits);
}
Fixed::Fixed( float nbr )
{
    _nbr = roundf(nbr * (1 << _numberBits)); // convert a float to int
}
Fixed::~Fixed(void)
{
    
}
Fixed::Fixed( const Fixed& copy )
{
    this->_nbr = copy.getRawBits();
}

void Fixed::setRawBits( int nbr ) 
{
    this->_nbr = nbr * (1 << _numberBits);
}

int Fixed::getRawBits( void ) const
{
    return this->_nbr;    
}

bool Fixed::operator<(const Fixed comp) const
{
    return(this->_nbr < comp.getRawBits());
}

bool Fixed::operator>(const Fixed comp) const
{
    return(this->_nbr > comp.getRawBits());
}

bool Fixed::operator<=(const Fixed comp) const
{
    return (this->_nbr <= comp.getRawBits());
}

bool Fixed::operator>=(const Fixed comp) const
{
    return (this->_nbr >= comp.getRawBits());
}

bool Fixed::operator==(const Fixed comp) const
{
    return (this->_nbr == comp.getRawBits());
}

bool Fixed::operator!=(const Fixed comp) const
{
    return (this->_nbr != comp.getRawBits());
}

Fixed Fixed::operator+( const Fixed &add ) const
{
    return Fixed( this->toFloat() + add.toFloat());
}

Fixed Fixed::operator-( const Fixed &add ) const
{
    return Fixed( this->toFloat() - add.toFloat());
}

Fixed Fixed::operator*( const Fixed &add ) const
{
    return Fixed( this->toFloat() * add.toFloat());
}

Fixed Fixed::operator/( const Fixed &add ) const
{
    return Fixed( this->toFloat() / add.toFloat());
}

float Fixed::toFloat(void) const
{
	return (float)_nbr / (1 << _numberBits);
}

int Fixed::toInt(void) const
{
	return _nbr >> _numberBits;
}

Fixed& Fixed::operator++( void )
{
    ++_nbr;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed Temp = *this;
    this->_nbr ++;
    return (Temp);
}

Fixed& Fixed::operator--( void )
{
    --_nbr;
    return (*this);
}

Fixed Fixed::operator--( int )
{
    Fixed Temp = *this;
    this->_nbr --;
    return (Temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (b);
    return(a);
        
}

Fixed& Fixed::min (Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (b);
    return(a);
}

const Fixed& Fixed::max (const Fixed &a, const Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (b);
    return(a);
}

Fixed& Fixed::max (Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (b);
    return(a);
}