#include <iostream>
#include <vector>
#include <cmath>
#include <map>
 
using namespace std;
int N,R;

int main()
{
  int n;
  int ret=0;

  cin >> N >> R;

  if (N>=10) {
    printf("%d\n", R);
  } else {
    printf("%d\n", R + 100*(10 - N));
  }

  return 0;
}
