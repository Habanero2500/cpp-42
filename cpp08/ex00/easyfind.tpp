/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:21:00 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/29 20:24:37 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>//
T easyfind( T& container, int value) 
{
    try
    {
        for(container::iterator it = container.begin(); it != v.end(); ++it)
        {
            if(*it == value)
               return *it;
        }
    }
    catch(std::exception& e)
    {
        cout << "The container does not contains the value " << value << endl;
    }
    
}





#endif 