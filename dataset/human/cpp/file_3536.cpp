#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y);
int main(){
  long n,i,j,ans,flag,pmin,mmax;
  cin>> n;
  flag=0;
  ans=0;
  pmin=1000000001;
  mmax=-1000000001;
  vector<int> a(n),b(n);
  for(i=0;i<n;i++)
  {
    cin >> a.at(i);
    b.at(i)=(-1)*a.at(i);
    if(b.at(i)>=0) {flag++;
     if(mmax<=a.at(i)) mmax=a.at(i);
         ans+=b.at(i);
                   }
    if(a.at(i)>0)
    {
      if(pmin>=a.at(i)) pmin=a.at(i);
      ans+=a.at(i);
    }
  }
  if(flag%2==0) cout << ans << endl;
  if(flag%2==1) 
  {
     if( pmin<=(-1)*mmax) cout << ans-pmin-pmin<< endl;
     if( pmin>(-1)*mmax)  cout << ans+mmax+mmax<< endl;
  }
       
                    
                    
  }
