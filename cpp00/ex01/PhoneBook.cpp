/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:21:40 by jmetayer          #+#    #+#             */
/*   Updated: 2026/06/26 14:02:48 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::display_one_contact(int i)
{
    std::cout << " - Index : " << i + 1 << std::endl;
    std::cout << " - First name : " << this->contact[i].get_first_name() << std::endl;
    std::cout << " - Last Name : " << this->contact[i].get_last_name() << std::endl;
    std::cout << " - Nickname : " << this->contact[i].get_nickname() << std::endl;
    std::cout << " - Phone number : " << this->contact[i].get_phone() << std::endl;
    std::cout << " - Darkest secret : " << this->contact[i].get_secret() << std::endl;
}
std::string PhoneBook::layout(std::string str) 
{
    
    int len = str.length();
    std::string result = "";
    
    if(len < 10)
    {
        int i = 10 - len;
        int o;
        for(o = 0; o < i; o++)
            result += ' ';
        result += str;
        return(result += "|");
    }
    else if (len == 10)
        return(str += "|");
    else
    {
        for(int i = 0; i < 9; i++)
            result += str[i];
        result += '.';
        return(result + "|");
    }
}

void PhoneBook::display_all_contact(int i)
{
    std::cout << "|         " << i + 1 << "|" ;
    std::cout << layout(this->contact[i].get_first_name());
    std::cout << layout(this->contact[i].get_last_name());
    std::cout << layout(this->contact[i].get_nickname()) << std::endl;
    std::cout << "|----------|----------|----------|----------|" <<std::endl;
}

void PhoneBook::search_contact(void)
{
    if(this->len == 0)
    {
        std::cout << "Your phone book is empty." << std::endl;
        return;        
    }
    std::string str;
    int index;
    for (int i = 0; i < this->len; i++)
    {
        if (i == 0)
        {
            std::cout << "|-------------------------------------------|" <<std::endl;
            std::cout << "|  Index   |First Name| Last Name| Nickname |" <<std::endl;
            std::cout << "|----------|----------|----------|----------|" <<std::endl;
        }
        display_all_contact(i);
    }
    std::cout << "Which contact would you like to display ?" << std::endl;
    std::cin >> str;
    index = ft_atoi(str);
    if (index < 1 || index > this->len || this->contact[index - 1].is_empty())
    {
        std::cout << "This index is not associated" << std::endl; 
        return ; 
    }
    display_one_contact(index - 1);
}
void PhoneBook::remove_and_add(Contact contact)
{
    this->contact[0] = this->contact[1];
    this->contact[1] = this->contact[2];
    this->contact[2] = this->contact[3];
    this->contact[3] = this->contact[4];
    this->contact[4] = this->contact[5];
    this->contact[5] = this->contact[6];
    this->contact[6] = this->contact[7];
    this->contact[7] = contact;
}

void PhoneBook::init_book(void)
{
    this->len = 0;
}

void PhoneBook::add_new_contact(void)
{
    Contact contact;
    contact.set_contact();
    if(this->len < 8)
    {
        this->contact[this->len]=contact;
        len++;
    }
    else
        remove_and_add(contact);
}
