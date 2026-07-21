#include<iostream>
using namespace std;
int main()
{
 ios_base::sync_with_stdio(false);
 std::cin.tie(NULL);
 std::cout.tie(NULL);
  long long int N,R;
  cin>>N>>R;
  long long int I;
  if(N>=10)
  {
    I=R;
    cout<<I<<endl;
  }
  else
  {
    I=R+100*(10-N);
    cout<<I<<endl;
  }
  
 
  
  
  
  
 return 0;
}
