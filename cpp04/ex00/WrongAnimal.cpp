/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:29:52 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    std::cout << "A new WrongAnimal is created thanks to the default constructor" << std::endl;
    _type = "Unkown";
}
WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal type " << _type << " is destroyed"
    << std::endl;
}
WrongAnimal::WrongAnimal (const WrongAnimal& other)
{
    std::cout << "Copy constructor is called to create " << other.getType() << std::endl;
    _type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "The operator overload is used !" << std::endl;
    if(this != &other)
    {
        _type = other.getType();
    }
    return (*this);
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "Classical constructor is used to create " << type << std::endl;
    _type = type;
}
std::string WrongAnimal::getType( void ) const 
{
    return (this->_type);
}

void WrongAnimal::makeSound ( void ) const
{
    std::cout << "I am a default WrongAnimal" << std::endl;
}