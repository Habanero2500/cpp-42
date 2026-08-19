/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:45:34 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/19 18:58:27 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#ifndef FORM_HPP
#define FORM_HPP

class Form{
    
    private :
    
    const std::string _name;
    bool _signed;
    const int _signer;
    const int _executer;
    
    public :

    //Orthodox Canonical Form
    Form( void );
    Form( std::string _name );
    Form( const Form& copy);
    Form& operator=(const Form& copy);
    ~Form( void );
}


#endif