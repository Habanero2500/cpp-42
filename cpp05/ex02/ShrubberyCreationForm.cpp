#include "ShrubberyCreationForm.hpp"

ShruberryCreationForm( void ) : AForm("Default_SCF", 0, 145, 137) 
{
    std::cout << "Default Constructor for SCF used" << std::endl;
}
ShruberryCreationForm& operator=( const ShruberryCreationForm& copy)
{
    if(this != &copy)
    {
        
    }
}
ShruberryCreationForm( const ShruberryCreationForm& copy)
{

}
~ShruberryCreationForm( void )
{

}
ShruberryCreationForm( std::string _copy )
{

}
void	execute(void) const
{

}

std::string const&	getTarget(void) const
{

}