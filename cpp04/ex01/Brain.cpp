/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:35:03 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/12 16:11:19 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Default constructor for brain is used" << std::endl;
}
Brain::~Brain( void )
{
    std::cout << "A Brain is destroyed" << std::endl;
}
Brain::Brain ( const Brain& brain )
{
    std::cout << "Copy constructor is used to create brain" << std::endl;   
    for( int i(0); i < 100 ; i++)
        _ideas[i] = brain._ideas[i];
}

Brain& Brain::operator=(const Brain& brain)
{
    std::cout << "A new brain appears thanks to the overload operator = " << std::endl;
    if(this != &brain)
    {
        for( int i(0) ; i < 100 ; i++)
            this->_ideas[i] = brain._ideas[i];
    }
    return *this;
}

void Brain::setIdeas( std::string idea, int i )
{
    this->_ideas[i] = idea;
}

void Brain::getIdeas( int nbr )
{
    if(nbr >= 0 && nbr < 100)
        std::cout << this->_ideas[nbr] << std::endl;
    else
        std::cout << " This animal does not have as many ideas" << std::endl;
}

