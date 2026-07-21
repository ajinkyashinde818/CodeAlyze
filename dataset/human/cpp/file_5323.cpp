#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<tuple>
#include<iomanip>
#include<climits>
#define ll long long int
#define mod 1000000007
#define pi acos(-1)
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n ,k;
  cin>>n>>k;
  if(n>=10)
   cout<<k;
 else 
   cout<<(10-n)*100+k;
  return 0;
}
