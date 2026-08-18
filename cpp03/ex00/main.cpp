/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:17 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/05 17:57:22 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
        // ClapTrap test1; // constructeur par défaut
    // ClapTrap test2("Test2"); // constructeur par dépendance
    // ClapTrap test3; 
    // test3 = test2; // opérateur d'affectation
    // std::cout << test3.getName() << std::endl; // test de l'opérateur d'affectation
    // ClapTrap test4(test2); // constructeur de copie

    ClapTrap v;
    ClapTrap a("Gaethje");
    ClapTrap b("Topuria");

    b.attack("Gaethje");
    b.takeDamage(3);
    b.beRepaired(3);
    for (int i = 0; i < 11; i++)
		a.attack("Topuria");
    return 0;
  
}