/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:08:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 13:20:37 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main( void )
{
    // std::cout << "** TEST FONCTIONNEMENT CLASS ANIMAL **" << std::endl;
    // Animal a;
    // Animal b("chat");
    // Animal c(b);
    // Animal d;
    // d = c;
    // std::cout << a.getType() <<std::endl;
    // std::cout << b.getType() <<std::endl;
    // std::cout << c.getType() <<std::endl;
    // std::cout << d.getType() <<std::endl;
    // a.makeSound();
    // b.makeSound();
    // c.makeSound();
    // d.makeSound(); 
    
    // std::cout << std::endl << "** TEST FONCTIONNEMENT CLASS CAT **" << std::endl;
    // Cat e;
    // Cat f("chat");
    // Cat g(f);
    // Cat h;
    // h = f;
    // std::cout << e.getType() <<std::endl;
    // std::cout << f.getType() <<std::endl;
    // std::cout << g.getType() <<std::endl;
    // std::cout << h.getType() <<std::endl;
    // e.makeSound();
    // f.makeSound();
    // g.makeSound();
    // h.makeSound(); 
        
    // std::cout << std::endl << "** TEST FONCTIONNEMENT CLASS DOG **" << std::endl;
    // Dog i;
    // Dog j("chien");
    // Dog k(j);
    // Dog l;
    // l = k;
    // i.makeSound();
    // j.makeSound();
    // k.makeSound();
    // l.makeSound(); 

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl << "Make the sound with the WrongClass and the WrongCat " << std::endl;
    
    const WrongAnimal* anim = new WrongAnimal();
    const WrongAnimal* cat = new WrongCat();
    std::cout << anim->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    anim->makeSound(); //will output the cat sound!
    cat->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete anim;
    delete cat;

return 0;
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