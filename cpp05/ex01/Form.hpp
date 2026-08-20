/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:45:34 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/20 18:45:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{
    
    private :
    
    const std::string _name;
    bool _signed;
    const int _signer;
    const int _executer;
    
    public :

    //Orthodox Canonical Form + constructors
    Form( void );
    Form( std::string name );
    Form( const Form& copy);
    Form& operator=(const Form& copy);
    ~Form( void );
    Form(std::string name, bool signos, int sign, int exec);

    //Getters and setters
    std::string getName( void )const;
    bool getSigned ( void ) const;
    int getSignerGrade ( void ) const;
    int getExecGrade ( void ) const;
    
    // Specific functions
    void beSigned(const Bureaucrat& signer);
    
    //Ecrire les fonctions du début
    //Faire les exceptions
    //Rajouter la fonction signForm chez les bureaucrates
};

std::ostream &operator<<(std::ostream& out, const Form& form);

#endif