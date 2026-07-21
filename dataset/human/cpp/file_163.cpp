#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>

using namespace std;
int main(void){
 long long int R,G,B,N;
 long long int ans=0;

 cin>>R>>G>>B>>N;
 
 for(int i=0; i<=(N/R);i++)
  for(int j=0; j<=(N/G);j++)if((N-i*R-j*G)>=0 &&(N-i*R-j*G)%B==0)ans++;

 cout<<ans<<endl;
 return 0;
}
