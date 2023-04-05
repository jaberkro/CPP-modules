#include "iter.hpp"
#include <iostream>
#include <string>

void	testLeaks(void)
{
	std::cout << std::endl;
	system("leaks iter -q");
}

void printOneLowerFloat(float f)
{
	std::cout << --f << " ";
}

void printOneHigherInt(int i)
{
	std::cout << ++i << " ";
}

void printAsChar(char c)
{
	std::cout << c << "  ";
}

int main (void)
{
	int i[] = {65, 66, 67, 68, 69};
	float f[] = {65.01, 66.02, 67.03, 68.04, 69.05};
	std::string s = "ABCDE";

	// print values of arrays
	std::cout << "\nvalues inside i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << " " << i[4] << "\n";
	std::cout << "values inside f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << "\n";
	std::cout << "values inside s: " << s.at(0) << " " << s.at(1) << " " << s.at(2) << " " << s.at(3) << " " << s.at(4) << "\n" << std::endl;

	// example with the printOneHigherInt function
	std::cout << "printOneHigherInt i:  ";
	::iter(i, 5, printOneHigherInt);
	std::cout << std::endl;
	std::cout << "printOneHigherInt f:  ";
	::iter(f, 5, printOneHigherInt);
	std::cout << std::endl;
	std::cout << "printOneHigherInt s:  ";
	::iter(s, 5, printOneHigherInt);
	std::cout << "\n" << std::endl;

	// example with the printOneLowerFloat function
	std::cout << "printOneLowerFloat i:  ";
	::iter(i, 5, printOneLowerFloat);
	std::cout << std::endl;
	std::cout << "printOneLowerFloat f:  ";
	::iter(f, 5, printOneLowerFloat);
	std::cout << std::endl;
	std::cout << "printOneLowerFloat s:  ";
	::iter(s, 5, printOneLowerFloat);
	std::cout << "\n" << std::endl;

	// example with the printAsChar function
	std::cout << "printAsChar i:    ";
	::iter(i, 5, printAsChar);
	std::cout << std::endl;
	std::cout << "printAsChar f:    ";
	::iter(f, 5, printAsChar);
	std::cout << std::endl;
	std::cout << "printAsChar s:    ";
	::iter(s, 5, printAsChar);
	std::cout << "\n" << std::endl;

	atexit(testLeaks);
	return 0;
}

