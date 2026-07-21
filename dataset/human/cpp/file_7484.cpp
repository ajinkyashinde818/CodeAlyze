#include <bits/stdc++.h>
using namespace std;
long long a[200005]; 
int main(){
int tmp;
int n;
scanf("%d",&n);
long long sum =0;
for(int i=0;i<n;i++){
   cin>>tmp;
   a[i]=tmp;
      sum += a[i]*1LL;
}
long long big = 2e15;
long long as=0;
for(int i=0;i<n-1;i++){
      as+= a[i];
      long long tt = labs(as*2 - sum);
      if(tt <= big){
            big = tt;

      }
}
cout<<big<<endl;

             
return 0;
}
