#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int N,R;
  cin >> N >> R;
  int Nr = 0;//表示レーディング
  int ans = 0;
  if(N >= 10){
    ans = R;
    
  }
  if(N < 10){
    Nr = 100 * (10 - N);
    ans = R + Nr;

  }
  cout << ans << endl;

  return 0; 
}
