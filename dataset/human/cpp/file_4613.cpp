#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<cstring>
#include<map>
#include<sstream>
 
using namespace std;
 
int main(){
  int N,R,Ans;
    cin>>N>>R;

  if(N<10){
  	Ans = R + (100 * (10 - N));
  }else{
    Ans = R;
  }
  cout<<Ans<<endl;
}
