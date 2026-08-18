/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:51:39 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:28:31 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "The cat default constructor is used" << std::endl;
}
Cat::~Cat(void)
{
    std::cout <<"A cat is destroyed" << std::endl;       
}
Cat & Cat::operator=(const Cat& other)
{
    std::cout << "Operator overload of = used" << std::endl; 
    if(this != &other)
        Animal("Cat");
    return *this;
}

Cat::Cat (const Cat& other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = other.Animal::getType();
}

void Cat::makeSound (void) const
{
    std::cout << "Meow meow meow" << std::endl; 
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Classical cat constructor is used to built a cat " << type << std::endl;
}
