#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
   int N;
   cin>>N;
   long A[N];
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   int count=0;
   for(int i=0;i<N;i++){
       if(A[i]<0){count++;}
   }
   long ans=0;
   if(count%2==0){
       for(int i=0;i<N;i++){
      ans+=abs(A[i]);
       }
   }
   if(count%2==1){
       for(int i=0;i<N;i++){
           A[i]=abs(A[i]);
       }
       sort(A,A+N);
       for(int i=1;i<N;i++){
           ans+=A[i];
       }
       ans-=A[0];
   }
   cout<<ans;
   return 0;
}
