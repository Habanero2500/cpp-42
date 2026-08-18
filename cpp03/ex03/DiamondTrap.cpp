/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:37:44 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 15:26:08 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(),  ScavTrap(), FragTrap()
{
    
    std::cout << "A new DiamondTrap is constructed thanks to the default constructor" << std::endl;
    this->_name = "Unnamed_DiamondTrap";
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    
}
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    std::cout << "A new DiamondTrap named " << name << " is constructed" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
    this->_name = other.DiamondTrap::_name;
    this->_hitPoints = other.getHitPoints();
    this->_energyPoints = other.getEnergyPoints();
    this->_attackDamage = other.getAttackDamage();
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap " << this->_name << " is destroyed" <<std::endl;
}
DiamondTrap & DiamondTrap::operator=( const DiamondTrap &other )
{
    std::cout <<"Overload operator = for DiamondTrap called" << std::endl;
    if (this != &other) {
     this->_name = other.getName();
     this->_hitPoints = other.getHitPoints();
     this->_energyPoints = other.getEnergyPoints();
     this->_attackDamage = other.getAttackDamage();
    }
    return(*this);
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "I am a DiamondTrap called " << this->_name 
    << " and my Claptrap name is " << ClapTrap::_name << std::endl;
}
void DiamondTrap::attack( const std::string& target )
{
    ScavTrap::attack(target);
}
std::string DiamondTrap::getDiamondName( void )
{
    return(_name);
}