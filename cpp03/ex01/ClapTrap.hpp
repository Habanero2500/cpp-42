/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:27 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 11:06:59 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

 class ClapTrap{
   
    protected : 

    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

    public :

    ClapTrap( void );
    ClapTrap( std::string name );
    ~ClapTrap( void );
    ClapTrap ( const ClapTrap& copy );
    ClapTrap& operator=( const ClapTrap& other );

    int getHitPoints(void) const; 
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
    std::string getName(void) const;
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif 