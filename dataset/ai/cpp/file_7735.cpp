/* Standalone example. */
#include <sstream>
#include <iostream>
int main() {
	std::stringstream stream;
	stream << 11;
	int result = 0; stream >> result;
	std::cout << result << '\n';
}
