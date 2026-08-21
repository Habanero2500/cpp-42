/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:24:57 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/21 16:04:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name("Default"), _signed(0), _signer(150), _executer(150)
{
    std::cout << "Form default constructor used" << std::endl;
}
Form::Form( std::string name ) : _name(name), _signed(0), _signer(150), _executer(150)
{
    std::cout << "Form classical constructor used" << std::endl;
}
Form::Form( const Form& copy) : _name(copy._name), _signed(copy._signed), _signer(copy._signer), _executer(copy._executer)
{
    std::cout << "Form copy constructor used" << std::endl;
}
Form& Form::operator=(const Form& copy)
{
    std::cout << "Form overload operator used" << std::endl;
    if(this != &copy)
        _signed = copy._signed;
    return *this;
}

Form::~Form( void )
{
    std::cout << "Form default destructor used" << std::endl;
}
Form::Form(std::string name, bool signos, int sign, int exec) : _name(name), _signed(signos), _signer(sign), _executer(exec)
{
    if( sign < 1 || exec < 1)
        throw Form::GradeTooHighException();
    else if ( sign > 150 || exec > 150 )
        throw Form::GradeTooLowException();
    else
        std::cout << "Form classical constructor used" << std::endl;

}

std::string Form::getName( void ) const
{
    return _name;
}
bool Form::getSigned ( void ) const
{
    return _signed;
}
int Form::getSignerGrade ( void ) const
{
    return _signer;
}
int Form::getExecGrade ( void ) const
{
    return _executer;
}

std::ostream& operator << (std::ostream& out, const Form& form)
{
    if( form.getSigned() == true)
    {
        out << "Form " << form.getName() << " is signed. Its signer had to be grade " << form.getSignerGrade()
        << " and its executer " << form.getExecGrade() << std::endl;    
    }
    else 
    {
        out << "Form " << form.getName() << " is not signed. Its signer has to be grade " << form.getSignerGrade()
        << " and its executer " << form.getExecGrade() << std::endl;
    }
    return out;
}

void Form::beSigned(const Bureaucrat& signer)
{
    if(signer.getGrade() > _signer)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form signer cannot be superior to 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form signer cannot be inferior to 150.";
}