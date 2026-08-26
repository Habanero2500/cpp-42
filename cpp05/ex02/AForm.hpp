/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:45:34 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/26 19:00:41 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm{
    
    private :
    
    const std::string _name;
    bool _signed;
    const int _signer;
    const int _executer;
    
    public :

    //Orthodox Canonical Form + constructors
    AForm( void );
    AForm( std::string name );
    AForm( const AForm& copy);
    AForm& operator=(const AForm& copy);
    ~AForm( void );
    AForm(std::string name, bool signos, int sign, int exec);

    //Getters and setters
    std::string getName( void )const;
    bool getSigned ( void ) const;
    int getSignerGrade ( void ) const;
    int getExecGrade ( void ) const;
    
    // Specific functions
    void beSigned(const Bureaucrat& signer);

    //Class 
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream& out, const AForm& form);



#endif