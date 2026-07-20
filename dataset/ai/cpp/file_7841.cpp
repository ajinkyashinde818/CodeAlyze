#include <sstream>
#include <iostream>
using namespace std;
int main() {
  stringstream stream;
  stream << 28;
  int result = 0; stream >> result;
  cout << result << '\n';
}
