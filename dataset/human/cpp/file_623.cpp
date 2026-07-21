#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int R, G, B, N, ans;
  cin >> R >> G >> B >> N;
  ans = 0;
  if(R == 1 && G == 1 && B == 1)
  {
    ans = (N+1)*(N+2)/2;
  }
  else{
      for(int i=0;i*R<=N;++i)
  {
    for(int j=0;j*G+i*R<=N;++j)
    {
      for(int k=0;i*R+k*B+j*G<=N;++k)
      {
        int K = N - i*R - j*G - k*B;
        if(K == 0)ans++;
      }
    }
  }
  }


  cout << ans << endl;

  return 0;
}
