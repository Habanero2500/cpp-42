/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:37:20 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 14:24:12 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public ClapTrap, virtual public ScavTrap, virtual public FragTrap {
    
    private :
    
    std::string _name;
    
    public :
    
    DiamondTrap( void );
    DiamondTrap& operator=( const DiamondTrap& other);
    DiamondTrap ( const DiamondTrap& other );
    DiamondTrap ( std::string name );
    ~DiamondTrap( void );
    
    void attack( const std::string &target);
    void whoAmI( void );
    std::string getDiamondName( void );
};


#endif