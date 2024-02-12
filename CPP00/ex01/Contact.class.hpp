/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:27:29 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 10:31:19 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include "Utils.hpp"

class Contact
{
    private:

    int id;
    std::string firstName;
    std::string lastName; 
    std::string nickName;
    std::string phoneNumber; 
    std::string darkestSecret;  
    void printMaxSize(const std::string& str, const long unsigned int maxSize) const;
    
    public:
    
    Contact();
    Contact(const int id, const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret);   
    void printDetail() const;
    void printShort() const;
};

#endif