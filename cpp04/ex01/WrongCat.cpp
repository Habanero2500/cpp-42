/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:51:39 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 13:23:00 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "The WrongCat default constructor is used" << std::endl;
}
WrongCat::~WrongCat(void)
{
    std::cout <<"A WrongCat is destroyed" << std::endl;       
}
WrongCat & WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Operator overload of = used" << std::endl; 
    if(this != &other)
        WrongAnimal("WrongCat");
    return *this;
}

WrongCat::WrongCat (const WrongCat& other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->_type = other.WrongAnimal::getType();
}

void WrongCat::makeSound (void) const
{
    std::cout << "Meow meow meow" << std::endl; 
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "Classical WrongCat constructor is used to built a WrongCat " << type << std::endl;
}
