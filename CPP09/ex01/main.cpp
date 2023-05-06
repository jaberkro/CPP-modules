#include "RPN.hpp"
#include <iostream>

int	solveExpression(std::string expression)
{
	RPN stack;

	for (size_t i = 0; i < expression.size(); i += 2)
	{
		if (isdigit(expression.at(i)))
		{
			stack.push_back(expression.at(i) - 48);
		}
		else
		{
			if (!stack.operation(expression.at(i)))
				return (0);
		}
	}
	std::cout << stack.getTop() << std::endl;
	return (1);
}

int isOperation(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (1);
	return (0);
}

int	validExpression(std::string expression)
{
	for (size_t i = 0; i < expression.size(); i++)
	{
		if (!isdigit(expression.at(i)) && !isOperation(expression.at(i)) && expression.at(i) != ' ')
			return (0);
		if (isOperation(expression.at(i)) && (i == 0 || expression.at(i - 1) != ' ' || (i < expression.size() - 1 && expression.at(i + 1) != ' ')))
			return (0);
		if (i % 2 == 0 && expression.at(i) == ' ')
			return (0);
		if (i % 2 == 1 && expression.at(i) != ' ')
			return (0);
	}
	return (1);
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return (1);
	}
	if (!validExpression(argv[1]))
	{
		std::cout << "Error: invalid expression: [" << argv[1]  << "]" << std::endl;
		return (1);
	}
	if (!solveExpression(argv[1]))
	{
		std::cout << "Error: impossible to resolve expression: stack empty when executing operation" << std::endl;
		return (1);
	}
	return (0);
}
