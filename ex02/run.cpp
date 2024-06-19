#include <ctime>
#include <iostream>
#include <iomanip> // for formatted time output

int main() 
{
	std::time_t t;
	std::time(&t);
	char timestamp[24];
	std::tm	*tm = std::localtime(&t);
	strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", tm);
	std::cout << timestamp << std::endl;
}
