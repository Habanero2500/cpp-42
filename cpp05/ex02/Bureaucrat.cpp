/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:45:59 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/28 15:15:33 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat ( void ): _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat ( const std::string name ): _name(name), _grade(150)
{
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
    if(this != &copy)
        _grade = copy._grade;
    return(*this);   
}

Bureaucrat::Bureaucrat (std::string name, int grade ) : _name( name )
{
    if( grade < 1 )
        throw Bureaucrat::GradeTooHighException();
    else if ( grade > 150 )
        throw Bureaucrat::GradeTooLowException();
    else 
        _grade = grade;
}

Bureaucrat::Bureaucrat ( const Bureaucrat& copy ) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
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
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::downGrade( void )
{
    if(_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << "." << std::endl;
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade can not be superior to 1.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade can not be inferior to 150.";
}
void Bureaucrat::signForm( AForm& form )
{
    if(form.getSigned() == true)
    {
        std::cout << _name << " cannot sign " << form.getName() << " because it's already signed." << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed the form " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << _name << " cannot sign, grade " << form.getSignerGrade() << " required." << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form) const
{
    //Erreur de Form pas signe
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

