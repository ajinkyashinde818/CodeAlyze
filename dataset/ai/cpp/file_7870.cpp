#include <sstream>
#include <iostream>
int main() {
	std::stringstream stream;
	stream << 57;
	int result = 0; stream >> result;
	std::cout << result << '\n';
}
