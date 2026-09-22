/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:09:05 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/22 17:25:49 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
    std::srand(std::time(NULL)); // Definit la seed
    int i(std::rand() % 3);
    if (i == 0)
    {
        std::cout << "The factory made an A" << std::endl;
        Base *test = new A; 
        return (test);
    }
    else if (i == 1)
    {
        std::cout << "The factory made a B" << std::endl;
        Base *test = new B;
        return (test);
    }
    else
    {
        std::cout << "The factory made a C" << std::endl;
        Base *test = new C;
        return (test);
    }
}
void identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL) // Renvoie nullptr si p n'est pas 
        std::cout << "Real type of this base is A" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "Real type of this base is B" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "Real type of this base is C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A&>(p); //refnull n'existe pas, le seul moyen de voir l'erreur est avec une exception car il est renvoye std::bad_cast
        (void)a;
        std::cout << "Real type of this base is A" << std::endl;
    }
    catch(...){}
    try{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Real type of this base is B" << std::endl;
    } 
    catch(...){}
    try{
        C& c = dynamic_cast<C&>(p) ;
        (void)c;
        std::cout << "Real type of this base is C" << std::endl;
    }
    catch(...){}
}

int main(void)
{
    Base* test = generate();
    identify(test);
    identify(*test);

    return 0;
}


