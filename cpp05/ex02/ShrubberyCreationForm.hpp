#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShruberryCreationForm : virtual public AForm 
{
    private :
    std::string _target;

    public :

    //Orthodox Canonical Form + constructors
    ShruberryCreationForm( void );
    ShruberryCreationForm& operator=( const ShruberryCreationForm& copy);
    ShruberryCreationForm( const ShruberryCreationForm& copy);
    ~ShruberryCreationForm( void );

    ShruberryCreationForm( std::string _copy );
    void	execute(void) const;
    //getter
    std::string const&	getTarget(void) const;

};

#endif