/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:19:25 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 23:09:53 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = "blank";
     std::cout << "Brain created" << std::endl;
}

Brain::Brain(const std::string type)
{
    std::cout << type << " Brain created" << std::endl;
    if (type == "Cat")
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = "Serve me, Slave.";
    }
    if (type == "Dog")
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = "I will protect you!";
    }
    std::cout << type << " first thought: " << ideas[0] << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy created" << std::endl;
	if(this != &src)
		for(int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
    std::cout << "Brain copy's first thought: " << ideas[0] << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}
