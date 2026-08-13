/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:04:01 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/29 13:22:24 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>

class Contact
{
//Public, protected or private
private : 
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public :
    void set_contact(void); // demande de saisie des informations du nouveau contact
    std::string get_first_name(void);
    std::string get_last_name(void);
    std::string get_nickname(void);
    std::string get_phone(void);
    std::string get_secret(void);
    bool is_empty(void);
};

std::string loop(std::string str, int number);
std::string display_and_add(std::string display);
bool is_numeric(std::string str);
bool is_alphabetic(std::string str);


#endif