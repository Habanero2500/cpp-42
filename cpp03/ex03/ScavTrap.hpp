/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:20:40 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/06 11:55:19 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    
    private :
    
    public :
    
    // Orthodox Canonical form
    ScavTrap ( void );
    ScavTrap ( const ScavTrap& other );
    ScavTrap& operator=( const ScavTrap& other );
    ~ScavTrap ( void );

    // Constructor
    ScavTrap ( std::string name );
    void guardGate( void );
    virtual void attack( const std::string &target);
};


#endif