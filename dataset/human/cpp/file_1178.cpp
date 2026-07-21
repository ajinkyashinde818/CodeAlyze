#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int count = 0;
  for (int r = 0; r * R <= N; r++)
  {
    for (int g = 0; r * R + g * G <= N; g++)
    {
      int rest = N - r * R - g * G;
      // cout << r << " " << g << " " << rest << endl;
      if (rest % B == 0)
      {
        count++;
        // cout << "count" << endl;
      }
    }
  }

  cout << count << endl;
  return EXIT_SUCCESS;
}
