#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 0;
  cin >> n;
  int an = 0;
  long long int b[n];
  long long int ans = 0;
  long long int min = 0;
  int num = 0;
  for(int i = 0;i < n;i++){
  	cin >> b[i];
      if(b[i] < 0){
      	b[i] *= -1;
        
      num++;
      }
    if(i == 0){
      min = b[i];
    }
    if(b[i] < min){
    	min = b[i];
      an = i;
    }
  }
  
  for(int i= 0;i < n;i++){
    	ans += b[i];
  }
  if(num %2 == 1){
  ans -= min*2;
  }
  cout << ans << endl;
}
