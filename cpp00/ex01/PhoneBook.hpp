/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:04:12 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/29 13:10:49 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
# include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private : 
    Contact contact[8];
    int len; 

public :
    void add_new_contact(void);
    void search_contact(std::string contact);
    void remove_and_add(Contact contact);
    void init_book(void);
    void search_contact(void);
    void display_all_contact(int i);
    void display_one_contact(int i);
    std::string layout(std::string str);
};

int ft_atoi(std::string str);
bool is_empty_or_whitespace(const std::string& str);
bool is_alphabetic_and_space(std::string str);





#endif
