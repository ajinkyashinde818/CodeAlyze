#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;


int main(){
int R,G,B,N;
cin>>R>>G>>B>>N;
int ans=0;
for(int i=0;i<=N/R;i++){
  for(int j=0;j<=(N-i*R)/G;j++){
    if((N-i*R-j*G)%B==0){
      ans+=1;
    }
  }
}

cout<<ans<<"\n";
return 0;
}
