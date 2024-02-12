/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:03:24 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 11:39:17 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main(void) 
{
    PhoneBook myPhoneBook;
    std::string str;
    
    std::cout << std::endl << "Welcome to " << BOLD << "myPhoneBook" << RESET << "." << std::endl << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "- to add a new Contact, type: " << BOLD << "ADD" << RESET << std::endl;
    std::cout << "- to search for a Contact, type: " << BOLD << "SEARCH" << RESET << std::endl;
    std::cout << "- to exit the Program, type: " << BOLD << "EXIT" << RESET << std::endl << std::endl;
    
    while(1)
    {
    std::cout << "Enter a Command: " << std::endl;
    std::getline(std::cin, str);
    if (std::cin.eof() || str.compare("EXIT") == 0)
        break ;
    if (str.compare("ADD") && str.compare("SEARCH"))
        myPhoneBook.wrongInput(str);
    else if (str.compare("SEARCH") == 0)
        myPhoneBook.search();
    else if (str.compare("ADD") == 0)
        myPhoneBook.add();
    printHr();
    }
    std::cout << "Exit" << std::endl;
    return (0);
}