/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:12 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:28:19 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
 
class Cat : virtual public Animal{
    
    private:
    
    public: 

    Cat (void);
    ~Cat (void); 
    Cat& operator=(const Cat& other);
    Cat (const Cat& other);
    Cat (std::string type);
    
    void makeSound(void) const;
};


#endif