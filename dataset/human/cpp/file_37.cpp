#include <iostream>

using namespace std;

int main()
{
  int R,G,B,N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for(int i=0;i*R<=N;i++)
    {
      for(int j=0;j<=min(G*j,N-i*R);j++)
	{
	  if((N-R*i-G*j)>=0 && (N-R*i-G*j)%B==0)
	    {
	      //	      cout << i << " " << j << " " << (N-R*i-G*j)/B << endl;
	      ans++;
	    }
	}
     }
  cout << ans << endl;
}
