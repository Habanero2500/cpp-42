/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:04:05 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/26 15:11:21 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    std::string command;
    PhoneBook book;

    std::cout << "Hello, here's yout personnal phonebook. You can ADD, SEARCH or EXIT" << std::endl;
    book.init_book();
    while(1)
    {
    if (!std::getline(std::cin, command))
    {
        std::cout << "\nCtrl + D, you left the Phonebook " << std::endl;
        std::exit(0); 
    }
    if(command.compare("ADD") == 0)
        book.add_new_contact();
    else if(command.compare("SEARCH") == 0)
        book.search_contact();
    else if(command.compare("EXIT") == 0)
        break;
    else
        continue;
    }
    return(0);
}