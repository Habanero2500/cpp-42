/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:12 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 11:31:45 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "A new ClapTrap is constructed thanks to the default constructor" << std::endl;
}

ClapTrap::ClapTrap ( std::string name )
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "A new ClapTrap named " << this->_name << " is created" << std::endl;
}


ClapTrap::~ClapTrap( void )
{
    std::cout << this->_name << " is destroyed" << std::endl;
}
ClapTrap::ClapTrap ( const ClapTrap& copy )
{
    this->_name = copy.getName();
    this->_hitPoints = copy.getHitPoints();
    this->_energyPoints = copy.getEnergyPoints();
    this->_attackDamage = copy.getAttackDamage();
    std::cout << "A new ClapTrap named " << this->_name << " is created" << std::endl;

}

ClapTrap & ClapTrap::operator=( const ClapTrap& other )
{
    std::cout <<"Overload operator = for ClapTrap called" << std::endl;
    if (this != &other) {
     this->_name = other.getName();
     this->_hitPoints = other.getHitPoints();
     this->_energyPoints = other.getEnergyPoints();
     this->_attackDamage = other.getAttackDamage();
    }
    return(*this);
}


int ClapTrap::getHitPoints(void) const
{
    return(this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
    return(this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

void ClapTrap::attack( const std::string& target )
{
    if( this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks "
        << target << " causing " << this->_attackDamage
        << " points of damage!" <<std::endl;
        this->_energyPoints -- ;
    }

    else 
        std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " take " 
    << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name
		<< " repaired himself by " 
		<< amount
		<< " points "
		<< std::endl;
		this->_hitPoints += amount;
		if (this->_hitPoints > 10)
			this->_hitPoints = 10;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is out of energy" << std::endl;
}
