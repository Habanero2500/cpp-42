/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:45:59 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/18 17:51:07 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

    Bureaucrat ( void );
    Bureaucrat ( std::string name );
    Bureaucrat& operator=( const Bureaucrat& copy );
    Bureaucrat ( const Bureaucrat &copy );
    ~Bureaucrat();

    void setName( std::string name );
    std::string getName( void );
    void setRange( int range );
    int getRange ( void );