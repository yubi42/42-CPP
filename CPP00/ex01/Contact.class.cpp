/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:45:46 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 10:58:02 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact()
{
    return ;
}

Contact::Contact(int id, const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret)
    : id(id), firstName(first), lastName(last), nickName(nick), phoneNumber(phone), darkestSecret(secret)
{
    return ;
}

void Contact::printDetail() const
{
    std::cout << "Contact ID: " << this->id << std::endl;
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
    std::cout << "Nick Name: " << this->nickName << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

void Contact::printMaxSize(const std::string& str, const long unsigned int maxSize) const
{
    const long unsigned int len = str.length();
    if (len <= maxSize)
        std::cout << std::setw(maxSize) << str;
    else
        std::cout << std::setw(maxSize) << str.substr(0, maxSize - 1) + ".";
}

void Contact::printShort() const
{
    const long unsigned int maxSize = 10;
    std::ostringstream id;

    if (this->id < 0)
        id << "ID";
    else
        id << this->id;
    this->printMaxSize(id.str(), maxSize);
    std::cout << " | ";
    this->printMaxSize(this->firstName, maxSize);
    std::cout << " | ";
    this->printMaxSize(this->lastName, maxSize);
    std::cout << " | ";
    this->printMaxSize(this->nickName, maxSize);
    std::cout << std::endl;
}
