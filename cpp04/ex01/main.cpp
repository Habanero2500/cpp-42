/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:08:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 16:05:54 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << std::endl << "**MANDATORY CHECK**" << std::endl << std::endl;
    //Init 4 animaux
    Animal *anim[3]; 
    for( int i(0); i < 4 ; i++ )
    {
        if (i < 2)
            anim[i] = new Dog();
        else
            anim[i] = new Cat();
    }
    //Check the sound 
    for( int i(0); i < 4; i++)
        anim[i]->makeSound();
    //Delete 
    for( int i(0); i < 4; i++ )
        delete anim[i];
    
    std::cout << std::endl << "**EXTRA CHECK ON DOG**" << std::endl << std::endl;
    
    std::cout << "Check idea setting and sound :" << std::endl; 
    Dog* gigi = new Dog("Gigi");

    gigi->getBrain()->setIdeas("Play", 1);
    gigi->getBrain()->setIdeas("Go out", 2);
    gigi->getBrain()->setIdeas("Eat", 3);
    
    
    Dog* hernest = new Dog(*gigi);
    Dog* lulu = new Dog();
    *lulu = *gigi;
    
    std::cout <<std::endl << "Check sound :" << std::endl; 
    gigi->makeSound();
    hernest->makeSound();
    lulu->makeSound();
    
    std::cout <<std::endl << "Check brain adress :" << std::endl; 
    std::cout << gigi->getBrain() << std::endl;
    std::cout << hernest->getBrain() << std::endl; 
    std::cout << lulu->getBrain() << std::endl;
    
    for (int i(0); i < 4; i++)
    {
        
        std::cout << "Gigi Ideas : " << std::endl;
        gigi->getBrain()->getIdeas(i);
        std::cout << std::endl;
    }
    for (int i(0); i < 4; i++)
    {
        
        std::cout << "Lulu Ideas : " << std::endl;
        lulu->getBrain()->getIdeas(i);
        std::cout << std::endl;
    }
    for (int i(0); i < 4; i++)
    {
        
        std::cout << "Hernest Ideas : " << std::endl;
        hernest->getBrain()->getIdeas(i);
        std::cout << std::endl;
    }
    delete lulu;
    delete hernest;
    delete gigi;
    
    return (0);
}

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     delete Animal;
//     delete 
//     return 0;
// }