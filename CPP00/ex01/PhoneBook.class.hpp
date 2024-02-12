/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:29:28 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/27 14:55:33 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
  private:

    bool maxEntries;
	int i;
	Contact contact[8];
    Contact header;
    void addCategory(const std::string& msg, std::string& input, const bool& phone);
	void printShort(void);

  public:
  
	PhoneBook(void);
	~PhoneBook(void);

	void add(void);
	void search(void);
	void wrongInput(const std::string& str);
};

#endif