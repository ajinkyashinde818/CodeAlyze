#include <iostream>

using namespace std;

int main()
{
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int res = 0;
  for (int i = 0; i * R <= N; i++) {
	for (int j = 0; j * G + i * R <= N; j++) {
	  int tmp = N - (i * R + j * G);
	  if (tmp % B == 0)
		res++;
	}
  }

  cout << res << endl;  

  return 0;
}
