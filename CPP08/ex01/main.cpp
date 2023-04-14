#include <iostream>
#include "Span.hpp"

void	testLeaks(void)
{
	std::cout << std::endl;
	system("leaks span -q");
}

int main (void)
{
	std::cout << "\n________SPAN OF SIZE 0_______________" << std::endl;
	try
	{
		Span sp = Span(0);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n________SPAN OF SIZE 1_______________" << std::endl;
	try
	{
		Span sp1 = Span(1);
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n________SPAN OF SIZE 2_______________" << std::endl;
	try
	{
		Span sp2 = Span(2);
		sp2.addNumber(1000);
		sp2.addNumber(100);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
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
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
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
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
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
			sp11000.addManySameNumbers(100, 300);
			sp11000.addIncrementingNumbers(105, 11999);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << sp11000.shortestSpan() << std::endl;
			std::cout << sp11000.longestSpan() << std::endl;
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
			sp25000.addIncrementingNumbers(0, 25000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << sp25000.shortestSpan() << std::endl;
			std::cout << sp25000.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	atexit(testLeaks);
	
	return 0;
}
