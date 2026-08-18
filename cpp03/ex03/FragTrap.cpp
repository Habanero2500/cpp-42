/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:40:45 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 11:54:51 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap ("Unnamed_FragTrap") 
{
    std::cout << "A new FragTrap is constructed thanks to the default constructor" << std::endl;
    _attackDamage = 30;
    _energyPoints = 100;
    _hitPoints = 100;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << this->_name << " is destroyed" <<std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout <<"Overload operator = for FragTrap called" << std::endl;
    if (this != &other) {
     this->_name = other.getName();
     this->_hitPoints = other.getHitPoints();
     this->_energyPoints = other.getEnergyPoints();
     this->_attackDamage = other.getAttackDamage();
    }
    return(*this);
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
    std::cout <<"Copy constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
        std::cout << "A new FragTrap named " << name << " is constructed" << std::endl;
        _attackDamage = 30;
        _energyPoints = 100;
        _hitPoints = 100;
}
void FragTrap::highFivesGuys(void)
{
    std::cout <<"Would you like to high five " << this->_name << " ? [yes/no]" << std::endl;
    std::string answer;
    std::cin >> answer;
    if(answer == "yes")
        std::cout << ":D" << std::endl;
    else if (answer == "no")
        std::cout << ":'(" << std::endl;
    else
        std::cout << "WTF" << std::endl;
}
void FragTrap::attack( const std::string& target )
{
    if( this->_energyPoints > 0)
    {
        std::cout << "FragTrap " << this->_name << " attacks "
        << target << " causing " << this->_attackDamage
        << " points of damage!" <<std::endl;
        this->_energyPoints -- ;
    }

    else 
        std::cout << "FragTrap " << this->_name << " is out of energy" << std::endl;

}