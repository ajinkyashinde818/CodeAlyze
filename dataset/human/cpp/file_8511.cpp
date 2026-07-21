#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>

using namespace std;

using ll = long long int; 

void prime(vector<int> &num, int n){
    for(int i=0;i<=n;i++){
        num[i] = 1;
    }
    num[0] = 0;
    num[1] = 0;
    num[2] = 1;

    for(int i=2;i<=sqrt(n);i++){
        if(num[i] == 1){
            for(int j=2;j<=n/i;j++){
                num[i*j] = 0;
            }
        }
    }
}


ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}
 
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main(void){
   
   int n,m;
   cin>>n>>m;

   vector<string> a(n);
   vector<string> b(m);

   for(int i=0;i<n;i++){
       string x;
       cin>>x;
       a[i] = x;
   }
   for(int i=0;i<m;i++){
       string x;
       cin>>x;
       b[i] = x;
   }

   if(n==1 && m==1){
       if(a[0] == b[0]){
           cout<<"Yes"<<endl;
           return 0;
       }else{
           cout<<"No"<<endl;
           return 0;
       }
   }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int ans = a[i].compare(j,m,b[0]);
           // cout<<ans<<endl;
            if(ans==0){
                int b_c = 1;
                int a_c = i+1;
                while(b_c<m && a_c < n){
                    ans = a[a_c].compare(j, m, b[b_c]);
                    //cout<<"enter"<<ans<<endl;
                    if(ans == 0){
                        b_c++;
                        a_c++;
                    }else{
                        break;
                    }
                    if(b_c == m){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
