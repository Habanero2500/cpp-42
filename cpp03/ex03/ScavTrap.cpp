/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:36 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 11:54:45 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap ("Unnamed_ScavTrap") 
{
    std::cout << "A new ScavTrap is constructed thanks to the default constructor" << std::endl;
    _attackDamage = 20;
    _energyPoints = 50;
    _hitPoints = 100;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << this->_name << " is destroyed" <<std::endl;
}
ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
    std::cout << "A new ScavTrap named " << name << " is constructed" << std::endl;
    _attackDamage = 20;
    _energyPoints = 50;
    _hitPoints = 100;
}

ScavTrap::ScavTrap ( const ScavTrap& other ) : ClapTrap(other)
{
    std::cout <<"Copy constructor ScavTrap called" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap& other )
{
    std::cout <<"Overload operator = for ScavTrap called" << std::endl;
    if (this != &other) {
     this->_name = other.getName();
     this->_hitPoints = other.getHitPoints();
     this->_energyPoints = other.getEnergyPoints();
     this->_attackDamage = other.getAttackDamage();
    }
    return(*this);
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode !" << std::endl;
}
void ScavTrap::attack( const std::string& target )
{
    if( this->_energyPoints > 0)
    {
        std::cout << "Scavtrap " << this->_name << " attacks "
        << target << " causing " << this->_attackDamage
        << " points of damage!" <<std::endl;
        this->_energyPoints -- ;
    }

    else 
        std::cout << "ScavTrap " << this->_name << " is out of energy" << std::endl;

}