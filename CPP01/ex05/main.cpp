/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:54:54 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/08 14:21:51 by jborner          ###   ########.fr       */
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
    harl.complain("WARNING");
    harl.print();
    harl.complain("DEBUG");
    harl.print();
}