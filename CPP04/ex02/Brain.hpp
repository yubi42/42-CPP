/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:15:08 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:52:49 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    
    public:
        Brain();
        Brain(const std::string _type);
        Brain(const Brain &src);
        Brain& operator=(const Brain& src);
        ~Brain();
};


#endif 