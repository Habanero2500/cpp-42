/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:45:59 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/19 17:57:12 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ): _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor is used" << std::endl;
}

Bureaucrat::Bureaucrat ( const std::string name ): _name(name), _grade(150)
{
    std::cout << "Bureaucrat classical constructor is used" << std::endl; 
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
    std::cout << "Bureaucrat operator overload = is called" << std::endl; 
    if(this != &copy)
        _grade = copy._grade;
    return(*this);   
}

Bureaucrat::Bureaucrat (std::string name, int grade ) : _name( name )
{
    if( grade < 1 )
        throw GradeTooHighException();
    else if ( grade > 150 )
        throw GradeTooLowException();
    else 
        _grade = grade;
    std::cout << "Bureaucrat classical constructor is used" << std::endl; 
}

Bureaucrat::Bureaucrat ( const Bureaucrat& copy ) : _name(copy._name), _grade(copy._grade)
{
    std::cout <<"Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor is called" << std::endl; 
}


std::string Bureaucrat::getName( void ) const 
{
    return (_name);
}
void Bureaucrat::setGrade( int grade )
{
    _grade = grade;
}
    
int Bureaucrat::getGrade ( void ) const
{
    return (_grade);
}

void Bureaucrat::upGrade( void )
{
    if(_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::downGrade( void )
{
    if(_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << "Bureaucrat " << value.getName() << " is grade " << value.getGrade() << std::endl;
	return out;
}

const char *GradeTooHighException::what() const throw()
{
    return "Grade can not be superior to 1.";
}

const char *GradeTooLowException::what() const throw()
{
    return "Grade can not be inferior to 150.";
}