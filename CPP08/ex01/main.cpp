#include <iostream>
#include "Span.hpp"

int main (void)
{
	{
		std::cout << "\n________SPAN OF SIZE 0_______________" << std::endl;
		Span sp = Span(0);
		try
		{
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
		{
		std::cout << "\n________SPAN OF SIZE 1_______________" << std::endl;
		Span sp1 = Span(1);
		try
		{
			std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "\n________SPAN OF SIZE 2_______________" << std::endl;
	try
	{
		Span sp2 = Span(2);
		sp2.addNumber(1000);
		sp2.addNumber(100);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n________SPAN OF SIZE 3_______________" << std::endl;
	try
	{
		Span sp3 = Span(3);
		sp3.addNumber(1000);
		sp3.addNumber(100);
		sp3.addNumber(-500);
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n________SPAN OF SIZE 5_______________" << std::endl;
	try
	{
		Span sp5 = Span(5);
		sp5.addNumber(6);
		sp5.addNumber(3);
		sp5.addNumber(17);
		sp5.addNumber(9);
		sp5.addNumber(11);
		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n________SPAN OF SIZE 11000___________" << std::endl;
	{
		Span sp11000 = Span(11000);
		try
		{
			sp11000.addNumber(6);
			sp11000.addNumber(3);
			sp11000.addNumber(17);
			sp11000.addNumber(9);
			sp11000.addNumber(11);
			sp11000.addIncrementingNumbers(sp11000.getVector().begin() + 100, sp11000.getVector().begin() + 200, 500);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest span: " << sp11000.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp11000.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "\n________SPAN OF SIZE 25000___________" << std::endl;
	{
		Span sp25000 = Span(25000);
		try
		{
			sp25000.addIncrementingNumbers(sp25000.getVector().begin(), sp25000.getVector().begin() + 25000, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest span: " << sp25000.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp25000.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	return (0);
}
