/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:19:25 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:37:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        _ideas[i] = "blank";
     std::cout << "Brain created" << std::endl;
}

Brain::Brain(const std::string _type)
{
    std::cout << _type << " Brain created" << std::endl;
    if (_type == "Cat")
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = "Serve me, Slave.";
    }
    if (_type == "Dog")
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = "I will protect you!";
    }
    std::cout << _type << " first thought: " << _ideas[0] << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy constructed" << std::endl;
	if(this != &src)
		for(int i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
    std::cout << "Brain copy's last thought: " << _ideas[99] << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assigned" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
		    std::cout << "Brain copy's last thought: " << _ideas[99] << std::endl;
	}
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}
