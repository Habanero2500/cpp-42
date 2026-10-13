/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:55 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/13 14:28:38 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "At leat one argument needed" << std::endl;
        return 1;
    }
    std::string args; 
    for (int i(1) ; i < argc ; ++i)
    {
        if(i > 1)
            args += " ";
        args += argv[i];
    }
    try
    {
        PmergeMe fj(args.c_str());      
        PmergeMe test(fj);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}