/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:24:57 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/21 16:04:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _name("Default"), _signed(0), _signer(150), _executer(150)
{
    std::cout << "AForm default constructor used" << std::endl;
}
AForm::AForm( std::string name ) : _name(name), _signed(0), _signer(150), _executer(150)
{
    std::cout << "AForm classical constructor used" << std::endl;
}
AForm::AForm( const AForm& copy) : _name(copy._name), _signed(copy._signed), _signer(copy._signer), _executer(copy._executer)
{
    std::cout << "AForm copy constructor used" << std::endl;
}
AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "AForm overload operator used" << std::endl;
    if(this != &copy)
        _signed = copy._signed;
    return *this;
}

AForm::~AForm( void )
{
    std::cout << "AForm default destructor used" << std::endl;
}
AForm::AForm(std::string name, bool signos, int sign, int exec) : _name(name), _signed(signos), _signer(sign), _executer(exec)
{
    if( sign < 1 || exec < 1)
        throw AForm::GradeTooHighException();
    else if ( sign > 150 || exec > 150 )
        throw AForm::GradeTooLowException();
    else
        std::cout << "AForm classical constructor used" << std::endl;

}

std::string AForm::getName( void ) const
{
    return _name;
}
bool AForm::getSigned ( void ) const
{
    return _signed;
}
int AForm::getSignerGrade ( void ) const
{
    return _signer;
}
int AForm::getExecGrade ( void ) const
{
    return _executer;
}

std::ostream& operator << (std::ostream& out, const AForm& AForm)
{
    if( AForm.getSigned() == true)
    {
        out << "AForm " << AForm.getName() << " is signed. Its signer had to be grade " << AForm.getSignerGrade()
        << " and its executer " << AForm.getExecGrade() << std::endl;    
    }
    else 
    {
        out << "AForm " << AForm.getName() << " is not signed. Its signer has to be grade " << AForm.getSignerGrade()
        << " and its executer " << AForm.getExecGrade() << std::endl;
    }
    return out;
}

void AForm::beSigned(const Bureaucrat& signer)
{
    if(signer.getGrade() > _signer)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm signer cannot be superior to 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm signer cannot be inferior to 150.";
}