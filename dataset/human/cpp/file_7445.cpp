#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   vector<long long> sum(N+1);
   sum[0]=0;
   for(int i=0;i<N;i++){
      sum[i+1]=sum[i]+a[i];
   }
   long long Mini=2000000007;
   for(int i=0;i<N-1;i++){
      Mini=min(Mini,abs(sum[N]-sum[i+1]-sum[i+1]));
   }
   cout<<Mini<<endl;
   return 0;
}
