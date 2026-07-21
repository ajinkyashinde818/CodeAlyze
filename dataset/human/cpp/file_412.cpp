#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

template <std::size_t N>
std::string to_string(const std::bitset<N>& bs)
{
  return bs.to_string<char, std::char_traits<char>, std::allocator<char> >();
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	long R, G, B, N;
	cin >> R >> G >> B >> N;
  	long count = 0;
  	for(int r=N/R;r>=0;r--)
    {
      for(int g=(N-r*R)/G;g>=0;g--)
      {
        if((N-r*R-g*G) % B == 0) count++;
      }
    }
  	cout << count << endl;
  	return 0;
}
