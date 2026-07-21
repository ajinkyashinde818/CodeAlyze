#include<iostream> 
#include<vector>
#include <cstdlib>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  
  long long min=1000000000000000000LL, sum1=a[0], sum2=0;
  for(int i=1;i<n;i++){
    	sum2+=a[i];
  }
  if(abs(sum1-sum2)<min) min=abs(sum1-sum2);
  for(int k=1;k<n-1;k++){
    sum1+=a[k];
    sum2-=a[k];
    if(abs(sum1-sum2)<min) min=abs(sum1-sum2);
  }
  	
  	
  
  cout << min;
  
  
  return 0;
}
