/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:22:51 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/25 15:06:23 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <limits>
#include <sstream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

void printHr(void);
bool numbersOnly(const std::string& input);
void inputId(int& id, int& maxId);
void check_eof(void);

#endif