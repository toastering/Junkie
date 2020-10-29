#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

std::string readline() {
	std::string returnme;
	std::getline(std::cin, returnme);
	return returnme;
}

int main() {
	srand(time(NULL));
	std::cout << "Please input file path output: ";
	std::string path = readline();
	std::string fbytes;
	std::cout << "Please input amount of bytes: ";
	int bytes = std::stoi(readline());
	fbytes.resize(bytes);

	for (int i = 0; i < bytes; i++) {
		fbytes[i] = rand() % 0xff; //max is 255 with /J cmd line flag in vs
	}

	std::ofstream stream(path, std::ios::binary | std::ios::ate);
	stream << fbytes;
	stream.close();

	std::cout << "Done!" << std::endl;

	main();
	return EXIT_SUCCESS;
}