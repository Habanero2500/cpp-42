/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:37:13 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/20 18:28:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Bureaucrat{
    
    private : 

    const std::string _name;
    int _grade;
    
    public : 

    //Orthodox canonical form + constructors
    Bureaucrat ( void );
    Bureaucrat& operator=( const Bureaucrat& copy );
    Bureaucrat ( const Bureaucrat &copy );
    ~Bureaucrat();
    Bureaucrat (std::string _name, int grade );
    Bureaucrat ( std::string name );

    //Getters and setters

    std::string getName( void ) const;
    void setGrade( int grade );
    int getGrade ( void ) const;
    
    //Increase and decrease grade
    void upGrade( void );
    void downGrade( void );
    void signForm( Form& form );
};

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

std::ostream& operator << (std::ostream& out, const Bureaucrat& value);


#endif