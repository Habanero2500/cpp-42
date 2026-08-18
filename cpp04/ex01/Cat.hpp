/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:12 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/13 12:52:30 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
 
class Cat : virtual public Animal{
    
    private:

    Brain *_brain;
    
    public: 

    Cat (void);
    ~Cat (void); 
    Cat& operator=(const Cat& other);
    Cat (const Cat& other);
    Cat (std::string type);
    
    void makeSound(void) const;
    Brain* getBrain( void );
};


#endif