/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:05:08 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 15:21:26 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"


PhoneBook::PhoneBook(void)
{
    this->maxEntries = false;
    this->i = 0;
    for (int j = 0; j < 8; j++)
    {
        this->contact[j] = Contact();
    }
    this->header = Contact();
    this->header = Contact(-1, "First Name", "Last Name", "Nickname", "Phone Number", "Dark Secret");
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void PhoneBook::add(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << std::endl;
    if (!this->maxEntries)
        std::cout << "Creating new Entry for ";
    else
        std::cout << "Changing Entry for ";
    std::cout << BOLD << "ID " << (this->i + 1) << RESET << std::endl;
    std::cout << std::endl;

    this->addCategory("First Name: ", firstName, 0);
    this->addCategory("Last Name: ", lastName, 0);
    this->addCategory("Nickname: ", nickName, 0);
    this->addCategory("Phone Number: ", phoneNumber, 1);
    this->addCategory("Dark Secret: ", darkestSecret, 0);

    this->contact[this->i] = Contact(this->i + 1, firstName, lastName, nickName, phoneNumber, darkestSecret);

    std::cout << std::endl;
    std::cout << BOLD << "Entry for ID " << this->i + 1;
    if (!this->maxEntries)
        std::cout << " added SUCCESS";
    else
        std::cout << " changed SUCCESS";
    std::cout << RESET << std::endl;

    this->i = (this->i + 1) % 8;
    if (this->i == 7)
        this->maxEntries = true;
}

void PhoneBook::addCategory(const std::string &msg, std::string &input, const bool &phone)
{
    std::cout << msg;
    if (std::getline(std::cin, input))
    {
        if (input.empty())
        {
            std::cout << BOLD << "Entry must be filled" << RESET << std::endl;
            this->addCategory(msg, input, phone);
        }
        if (!phone || numbersOnly(input))
            return;
    }
    check_eof();
    std::cin.clear();
    if (!phone)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << BOLD << "Input INVALID" << RESET << std::endl;
    this->addCategory(msg, input, phone);
}

void PhoneBook::search(void)
{
    int id = -1;
    int maxId = 8;

    printHr();
    std::cout << "myPhoneBook Entries: " << std::endl;
    std::cout << std::endl;
    this->header.printShort();
    if (!this->maxEntries && this->i == 0)
    {
        std::cout << std::endl;
        std::cout << BOLD << "No Entries found" << RESET << std::endl;
        return;
    }
    this->printShort();
    std::cout << std::endl;
    std::cout << "To see whole Entry, type in Entry ID: " << std::endl;
    if (!this->maxEntries)
        maxId = this->i;
    inputId(id, maxId);
    std::cout << std::endl;
    if (std::cin)
        this->contact[id - 1].printDetail();
}

void PhoneBook::printShort(void)
{
    int printSize;

    printSize = 8;
    if (!this->maxEntries)
        printSize = this->i;
    for (int i = 0; i < printSize; i++)
        this->contact[i].printShort();
}

void PhoneBook::wrongInput(const std::string &str)
{
    std::cout << std::endl;
    std::cout << BOLD << str << RESET << " is not a valid Command." << std::endl;
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "- to add a new Contact, type: " << BOLD << "ADD" << RESET << std::endl;
    std::cout << "- to search for a Contact, type: " << BOLD << "SEARCH" << RESET << std::endl;
    std::cout << "- to exit the Program, type: " << BOLD << "EXIT" << RESET << std::endl
              << std::endl;
}
