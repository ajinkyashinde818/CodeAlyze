#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

long long N;

vector<long long> A;

using Graph=vector<vector<int>>;

Graph E,O;

int dfs(int n,int m)
{


}
int main()
{
  cin >> N;
  long long i,j,k,m,count=0;

  A.assign(N,0);
  j=0;
  m=1000000000;
  for(i=0;i<N;i++)
  {
    cin >> k;
    if(k>0)
    {
      j+=k;
    }
    else
    {
      count++;
      j+=-k;
    }
    m=min(m,abs(k));
  }
  
  if(count%2==0)
  {
    cout << j;
  }
  else
  {
    cout << j-2*m;
  }


}
