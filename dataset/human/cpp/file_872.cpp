#include <bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	int n;
	long long R, G, B, N;
    long long count = 0;
    cin >> R >> G >> B >> N;
 
    for(long long i = 0; i <= N; i++)
	{
      for(long long j = 0; j <= N-i; j++)
	  {
        if((N >= ((R*i)+(G*j))) && ((N - ((R*i)+(G*j))) % B == 0)) 
			count++;
      }
    }
 
    cout << count << endl;
	return 0;
}
