#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, const char * argv[]) {
 
 
 
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    /////////////////////
    // Write code below /
    /////////////////////
    
    int N,R;
  
  	cin>>N>>R;
  
  	if(N < 10){
      R = R + 100 * (10 - N);
    }
  
  	cout<<R<<endl;
 
	
 
    return 0;
}
