#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
int main(void) {
    
   int n;
   cin>>n;
    int a[200000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

   long long int sum[200000];
    sum[0]=a[0];

   for(int i=1;i<n;i++){
       sum[i]=sum[i-1]+a[i];
      // cout<<sum[i]<<" ";
   }  

    //cout<<endl;
    long long int min=2*pow(10,9);

   for(int i=0;i<n-1;i++){
       if(min > abs(sum[i]-(sum[n-1]-sum[i]))){
           min = abs(sum[i]-(sum[n-1]-sum[i]));
       }
   }

   cout<<min<<endl;

    return 0;
}
