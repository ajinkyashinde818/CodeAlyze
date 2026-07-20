#include <sstream>
#include <iostream>
int main()
{
    std::stringstream stream;
    stream << 78;
    int result = 0; stream >> result;
    std::cout << result << '\n';
}
