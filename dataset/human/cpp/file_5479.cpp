#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static int
solve(int N, int R)
{
  return 10 <= N ? R : R + 100 * (10 - N);
}

int
main()
{
  int N, R;
  cin >> N >> R;
  cout << solve(N, R) << endl;
  return 0;
}
