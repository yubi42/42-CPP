/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:46:27 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/29 16:03:31 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool valid_files(std::ifstream& infile, std::ofstream& outfile)
{
    if (!infile.is_open())
    {
        std::cout << "Unable to open infile" << std::endl;
        return (false);
    }
    if (!outfile.is_open())
    {
        std::cout << "Unable to open oufile" << std::endl;
        infile.close();
        return (false);
    }
    return (true);
}

void write_replace_string(std::string line, const std::string& find, const std::string& replace, std::ofstream& outfile)
{
    std::size_t i = 0;
    std::size_t exists = line.find(find);

    if ( exists != std::string::npos)
    {
        while (i < exists)
            outfile << line[i++];
        outfile << replace;
        if (line[i + find.length()])
            write_replace_string(&line[i + find.length()], find, replace, outfile);
    }
    else
        outfile << line;
    outfile << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);

    std::string line;
    std::ifstream infile(av[1]);
    std::ofstream outfile("new_file");
    std::string find(av[2]);
    std::string replace(av[3]);

    if (!valid_files(infile, outfile))
        return (1);
    while( getline(infile, line))
        write_replace_string(line, find, replace, outfile);
    infile.close();
    outfile.close();
    return (0);
}