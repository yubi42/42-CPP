/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:15:16 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 15:08:50 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool numbersOnly(const std::string &input)
{
    for (long unsigned int i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std::cout << "Enter Numbers Only" << std::endl;
            return false;
        }
    }
    return true;
}

void printHr(void)
{
    std::cout << std::endl;
    std::cout << std::setfill('=') << std::setw(34) << "" << std::setfill(' ') << std::endl;
    std::cout << std::endl;
}

void check_eof(void)
{
        if (std::cin.eof())
    {
        std::cout << std::endl;
        std::cout << "Exit" << std::endl;
        exit(0);
    }
}

void inputId(int& id, int& maxId)
{
    if (std::cin >> id && ((id > 0 && id <= 8)) && id <= maxId)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    check_eof();
    std::cout << "Enter ID between 1 and " << maxId << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    inputId(id, maxId);
}