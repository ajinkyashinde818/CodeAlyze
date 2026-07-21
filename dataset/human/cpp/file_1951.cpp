#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    else if (a % b)
        return gcd(b, a % b);
    else
        return b;
}
int main()
{
  int n;
  cin>>n;
  long A[n];
  int cnt=0;
  for(int i=0; i<n; i++){
    cin>>A[i];
    if(A[i]<0)cnt++;
  }
  long long sum=0;
  if(cnt%2==0){
    for(int i=0; i<n; i++){
      sum+=abs(A[i]);
    }
    cout<<sum<<endl;
  }
  else{
    vector<long long>v;
    for(int i=0; i<n; i++){
      v.push_back(abs(A[i]));
      sum+=abs(A[i]);
    }
    sort(v.begin(),v.end());
    cout<<sum-2*v[0]<<endl;
  }

    
}
