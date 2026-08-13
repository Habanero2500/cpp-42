/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:03:58 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/29 11:52:20 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_contact(void)
{
    std::string result;
    
    this->firstName = loop("First name : ", 2);
    this->lastName = loop("Last name : ", 2);
    this->nickname = loop("Nickname : ", 2);
    this->phoneNumber = loop("Phone number : ", 0);
    this->darkestSecret = loop("Darkest secret : ", 1);
}
std::string Contact::get_first_name(void)
{
    return(this->firstName);
}
std::string Contact::get_last_name(void)
{
    return(this->lastName);
}
std::string Contact::get_nickname(void)
{
    return(this->nickname);   
}
std::string Contact::get_phone(void)
{
    return(this->phoneNumber);   
}
std::string Contact::get_secret(void)
{
    return(this->darkestSecret);   
}

bool Contact::is_empty(void)
{
    return(this->firstName.empty());
}
