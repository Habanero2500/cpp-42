/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:41:12 by jmetayer          #+#    #+#             */
/*   Updated: 2026/08/11 19:29:23 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
 
class WrongCat : virtual public WrongAnimal{
    
    private:
    
    public: 

    WrongCat (void);
    ~WrongCat (void); 
    WrongCat& operator=(const WrongCat& other);
    WrongCat (const WrongCat& other);
    WrongCat (std::string type);
    
    void makeSound(void) const;
};


#endif