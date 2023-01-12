/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 20:50:59 by jaberkro      #+#    #+#                 */
/*   Updated: 2023/01/12 11:55:47 by jaberkro      ########   odam.nl         */
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
			newLine.append(line.substr(start, end - start));
			newLine.append(s2);
			start = end + s1.size();
			if (start >= line.size() - 1)
				break ;
		}
	}
	newLine.append(line.substr(start, end));
	return (newLine);
}

bool	infileOpen(std::ifstream	*file)
{
	if (file->is_open())
		return (1);
	std::cout << "Error: unable to open input file" << std::endl;
	return (0);
}

bool	outfileOpen(std::ofstream	*file)
{
	if (file->is_open())
		return (1);
	std::cout << "Error: unable to open output file" << std::endl;
	return (0);
}

void	openFilesCopyLines(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	originalFile;
	std::ofstream	newFile;
	std::string		line;

	if (filename.size() == 0 || s1.size() == 0 || s2.size() == 0)
	{
		std::cout << "Error: empty argument" << std::endl;
		return ;
	}
	originalFile.open(filename);
	if (!infileOpen(&originalFile))
		return ;
	newFile.open(filename.append(".replace"));
	if (!outfileOpen(&newFile))
	{
		originalFile.close();
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
