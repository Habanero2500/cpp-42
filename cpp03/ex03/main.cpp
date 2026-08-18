/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:29 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 15:35:27 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


int main(void)
{

	std::cout << "*** VERIFICATION A LA CREATION AVEC CONSTRUCTEUR PAR DEFAUT ***" 
	<< std::endl << std::endl;
	DiamondTrap a;
	std::cout << "ClapTrap name : " << a.ScavTrap::getName() <<std::endl;
	std::cout << "DiamondTrap name : " << a.getDiamondName() <<std::endl;
	std::cout << "Hit Points : " << a.getHitPoints() <<std::endl;
    std::cout << "Energy Points : " << a.getEnergyPoints() <<std::endl;
	    std::cout << "Damage : " << a.getAttackDamage() <<std::endl;
	a.whoAmI();
    a.attack("Imu");
	std::cout << std::endl;
	
	std::cout << "*** VERIFICATION A LA CREATION AVEC CONSTRUCTEUR CLASSIQUE ***" 
	<< std::endl << std::endl;
    DiamondTrap b("Loki");
	std::cout << "ClapTrap name : " << b.ScavTrap::getName() <<std::endl;
	std::cout << "DiamondTrap name : " << b.getDiamondName() <<std::endl;
	std::cout << "Hit Points : " << b.getHitPoints() <<std::endl;
    std::cout << "Energy Points : " << b.getEnergyPoints() <<std::endl;
	std::cout << "Damage : " << b.getAttackDamage() <<std::endl;
	b.whoAmI();
    b.attack("Imu");
	std::cout << std::endl;
	
	std::cout << "*** VERIFICATION A LA CREATION AVEC CONSTRUCTEUR DE COPIE ***" 
	<< std::endl << std::endl;
    DiamondTrap c(b);
	std::cout << "ClapTrap name : " << c.ScavTrap::getName() <<std::endl;
	std::cout << "DiamondTrap name : " << c.getDiamondName() <<std::endl;
	std::cout << "Hit Points : " << c.getHitPoints() <<std::endl;
	std::cout << "Energy Points : " << c.getEnergyPoints() <<std::endl;
    std::cout << "Damage : " << c.getAttackDamage() <<std::endl;
    c.whoAmI();
	c.attack("Imu");
	


	std::cout << std::endl;
	std::cout << "*** VERIFICATION A LA CREATION AVEC SURCHARGE DE L'OP = ***" 
	<< std::endl << std::endl;
    DiamondTrap d = c;
	std::cout << "ClapTrap name : " << d.ScavTrap::getName() <<std::endl;
	std::cout << "DiamondTrap name : " << d.getDiamondName() <<std::endl;
	std::cout << "Hit Points : " << d.getHitPoints() <<std::endl;
    std::cout << "Damage : " << d.getAttackDamage() <<std::endl;
    std::cout << "Energy Points : " << d.getEnergyPoints() <<std::endl;
    d.whoAmI();
	d.attack("Imu");

    std::cout << std::endl;


    return 0;
    
}