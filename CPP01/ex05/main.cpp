/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:54:54 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/31 18:32:46 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("ERROR");
    harl.print();
    harl.complain("INFO");
    harl.print();
    harl.complain("pups");
    harl.print();
    harl.complain("ERROR");
    harl.print();
    harl.complain("DEBUG");
    harl.print();
}