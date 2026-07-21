#include<bits/stdc++.h>  
using namespace std;  
 
int main() {  
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(30);  
  	int N;
  	int R;
  	cin>>N>>R;
  	if(N>=10){
      cout<<R;
    }
  	else{
      cout<<(R+100*(10-N));
    }
    return 0;  
}
