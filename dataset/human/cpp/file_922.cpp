#include<bits/stdc++.h>
using namespace std; 
int main(){
  int box[3]={0},n;
  cin >> box[0] >> box[1] >> box[2];
  cin >> n;
  int num = 0;
  int sum = 0;
  for(int i=0;i<=3000;i++){
	for(int j=0;j<=3000;j++){
	  num = n-box[0]*i-box[1]*j;

	  if(num%box[2] == 0 && num>=0) sum++;
    }
  }
  cout << sum << "\n";
}
