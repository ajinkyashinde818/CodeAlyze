#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<map>
using namespace std;

int main(){
   int N,M;
   cin>>N>>M;
   const int nmax=50;
   char A[nmax][nmax],B[nmax][nmax];
   for(int y=0;y<N;y++){
     for(int x=0;x<N;x++){
       cin>>A[y][x];
      }
   }
   for(int y=0;y<M;y++){
     for(int x=0;x<M;x++){
       cin>>B[y][x];
     }
   }
   bool exist=false;

   for(int ly=0;ly<N;ly++){
     for(int lx=0;lx<N;lx++){
       if(ly+M-1>=N||lx+M-1>=N)continue;

       bool match=true;
       for(int y=0;y<M;y++){
         for(int x=0;x<M;x++){
           if(A[ly+y][lx+x]!=B[y][x])match=false;
         }
       }
       if(match)exist=true;
     }
   }
   if(exist){
     cout<<"Yes"<<endl;
   }
   else{
     cout<<"No"<<endl;
   }
   return 0;
}
