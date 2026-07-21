#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



int main(int argc, char* argv[])
{
  using std::cin;
  using std::cout;
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int res = 0;
  for (int r = 0; r*R <= N; ++r)
  {
    for (int g = 0; g*G <= N-r*R; ++g)
    {
      const int rem = N - r*R - g*G;
      if (rem % B) continue;
      ++res;
    }
  }
  cout << res << "\n";

  return 0;
}
