/* 
*	
*	AUTHOR :- @soham01 
*		// "WORK HARD AND NEVER GIVE UP" //
*
*/
#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int a,b;
  cin>>a>>b;
  if(a<10)
  {
    cout<<b+(10-a)*100<<endl;
  }
  else if(a>=10)
  {
    cout<<b<<endl;
  }
	return 0;
}
