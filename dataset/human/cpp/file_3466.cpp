#include <iostream>

using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  long long sum=0;
  int min=1000000001;
  int neg=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i]<0)
    {
      neg++;
      a[i]*=-1;
    }
    sum+=a[i];
    if(a[i]<min)
      min=a[i];
  }
  if(neg%2!=0)
    sum-=(2*min);
  cout<<sum;
}
