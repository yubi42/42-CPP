/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:59:58 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/31 19:15:55 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl
{
private:
    std::pair<std::string, void (Harl::*)()> msg[4];
    std::string complaint;
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:

    Harl();
    ~Harl();
    void complain( std::string level );
    void print( void );
};

#endif