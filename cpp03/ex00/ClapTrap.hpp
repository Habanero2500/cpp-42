/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:14 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/03 16:20:15 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

 class ClapTrap{
   
    private : 

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

    int getHitPoints(void) const; //ok
    int getEnergyPoints(void) const; //ok
    int getAttackDamage(void) const; //ok
    std::string getName(void) const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif 