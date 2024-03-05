/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:08:08 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/26 13:58:45 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>

int main(int ac, char **av) 
{
    int i;
    int j;
    std::string str;

    i = 1;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
                str += toupper(av[i][j++]);
            std::cout << str;
            str.clear();
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}

