/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:21:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/30 16:00:15 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"




int main ( void )
{
    
     
    
    std::vector<int> v;
    for( int i(0); i < 50; i++)
        v.push_back(i);

    std::cout << "**** TEST WITH VECTOR ****" << std::endl;
    std::cout << "- Good test : " << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 26);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }
    
    std::cout << "- Exception test : " << std::endl << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 58);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }

    
    ///////////////////////////////////////////////////////////

    std::list<int> l;
    for( int i(0); i < 50; i++)
        l.push_back(i);

    std::cout << std::endl << "**** TEST WITH LIST ****" << std::endl;
    std::cout << "- Good test : " << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(l, 26);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }
    
    std::cout << "- Exception test : " << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(l, 58);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }

        ///////////////////////////////////////////////////////////

    std::deque<int> d;
    for( int i(0); i < 50; i++)
        d.push_back(i);

    std::cout << std::endl << "**** TEST WITH DEQUE ****" << std::endl;
    std::cout << "- Good test : " << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(d, 26);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }
    
    std::cout << "- Exception test : " << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(d, 58);
        std::cout << "Value found " << *it << std::endl;          
    }
    catch ( std::exception& e )
    {
        cout << e.what() << endl;
    }


    
    
}
