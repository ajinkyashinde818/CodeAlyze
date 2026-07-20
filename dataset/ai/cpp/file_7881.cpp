#include <sstream>
#include <iostream>
using namespace std;
int main() {
  stringstream stream;
  stream << 68;
  int result = 0; stream >> result;
  cout << result << '\n';
}
