/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:52:08 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/03 16:59:37 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "**** MANDATORY MAIN ****" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
///////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl << "**** EXTRA TEST *****" << std::endl << std::endl;
    
    std::cout << " - Copy constructor : " << std::endl;
    MutantStack<int> test1 = mstack;
    
    for(MutantStack<int>::iterator it = test1.begin(); it != test1.end() ; ++it)
        std::cout << *it << std::endl;
    
    std::cout << " - Display with reverse_iterator : " << std::endl;
    for(MutantStack<int>::reverse_iterator it = test1.rbegin(); it != test1.rend() ; ++it)
        std::cout << *it << std::endl; 
    
    return 0;
}