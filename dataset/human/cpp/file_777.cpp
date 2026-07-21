#include<bits/stdc++.h>
using namespace std;
int main()
{
int ans=0;
 int R,G,B,N;
  cin>>R>>G>>B>>N;
  for(int i=0;i<=N;i++)
  {
  for(int j=0;j<=N;j++)
  {
  if(N-i*R-j*G<0)break;
    if((N-i*R-j*G)%B==0)ans++;
  }
  }
cout<<ans;
}
