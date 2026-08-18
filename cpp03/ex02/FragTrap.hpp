/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:40:53 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/05 15:52:59 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    private :

    public :
    
    FragTrap ( void );
    ~FragTrap ( void );
    FragTrap& operator=(const FragTrap& other);
    FragTrap( const FragTrap& other );

    FragTrap( std:: string name );
    void highFivesGuys(void);
    void attack( const std::string &target);
};


#endif