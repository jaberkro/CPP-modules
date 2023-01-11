/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 20:50:59 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/11 22:07:52 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string	replaceLine(std::string line, std::string s1, std::string s2)
{
	unsigned long	end = line.size();
	unsigned long	start = 0;
	std::string		newLine;

	while (42)
	{
		end = line.find(s1, start);
		if (end == std::string::npos)
		{
			break ;
		}
		else
		{
			newLine.append(line.substr(start, end));
			newLine.append(s2);
			start = end + s1.size();
			if (start >= line.size() - 1)
				break ;
		}
	}
	newLine.append(line.substr(start, end));
	return (newLine);
}

void	openFilesCopyLines(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	originalFile;
	std::ofstream	newFile;
	std::string		line;

	if (filename.size() == 0 || s1.size() == 0 || s2.size() == 0)
		std::cout << "Error: empty argument" << std::endl;
	originalFile.open(filename);
	if (!originalFile.is_open())
	{
		std::cout << filename << ": Unable to open input file" << std::endl;
		return ;
	}
	newFile.open(filename.append(".replace"));
	if (!newFile.is_open())
	{
		originalFile.close();
		std::cout << filename << ": Unable to open output file" << std::endl;
		return ;
	}
	while (getline(originalFile, line))
	{
		if (s1.size() != 0)
			line = replaceLine(line, s1, s2);
		newFile << line << std::endl;
	}
	originalFile.close();
	newFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	else
	{
		openFilesCopyLines(argv[1], argv[2], argv[3]);
	}
	return (0);
}
