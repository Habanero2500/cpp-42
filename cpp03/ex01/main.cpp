/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:29 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/05 18:36:43 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap z;
    ScavTrap a("Loki");
    std::cout << "Damage : " << a.getAttackDamage() <<std::endl;
    std::cout << "Hit Points : " << a.getHitPoints() <<std::endl;
    std::cout << "Energy Points : " << a.getEnergyPoints() <<std::endl;
    a.attack("Imu");
    
    ScavTrap b(a);
    ScavTrap c;
    c = a;
    std::cout << "Damage de A :" << a.getAttackDamage() << std::endl;
    std::cout << "Hit Points de A :" << a.getHitPoints() << std::endl;
    std::cout << "Energy Points de A :" << a.getEnergyPoints() << std::endl;
    
    std::cout << "Constructeur de copie : Damage de B :" << b.getAttackDamage() << std::endl;
    std::cout << "Constructeur de copie : Hit Points de B :" << b.getHitPoints() << std::endl;
    std::cout << "Constructeur de copie : Energy Points de B :" << b.getEnergyPoints() << std::endl;

    std::cout << "Operateur d'affectation = : Damage de C :" << c.getAttackDamage() << std::endl;
    std::cout << "Operateur d'affectation = : Hit Points de C :" << c.getHitPoints() << std::endl;
    std::cout << "Operateur d'affectation = : Energy Points de C :" << c.getEnergyPoints() << std::endl;

    a.guardGate();

    return 0;
    
}