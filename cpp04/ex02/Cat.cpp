/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:51:39 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 12:53:25 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    _brain = new Brain;
    std::cout << "The cat default constructor is used" << std::endl;
}
Cat::~Cat(void)
{
    delete _brain ;
    std::cout <<"A cat is destroyed" << std::endl;       
}
Cat & Cat::operator=(const Cat& other)
{
    std::cout << "Operator overload of = used" << std::endl; 
    if(this != &other)
    {
        this->_type = other.getType();
        *this->_brain = *other._brain;
    }
    return *this;
}

Cat::Cat (const Cat& other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = other.Animal::getType();
    this->_brain = new Brain(*other._brain);    
}

void Cat::makeSound (void) const
{
    std::cout << "Meow meow meow" << std::endl; 
}

Cat::Cat(std::string type) : Animal(type)
{
    _brain = new Brain();
    std::cout << "Classical cat constructor is used to built a cat " << type << std::endl;
}
Brain* Cat::getBrain( void )
{
    return this->_brain;
}
