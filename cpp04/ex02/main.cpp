/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:08:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 14:51:36 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main( void )
{ 
    // Animal* animal = new Animal;
    // animal->makeSound();
    
    Animal* test = new Dog();
    test->makeSound();
    
    Animal* testcat = new Cat();
    testcat->makeSound();
    
    return (0);
}
