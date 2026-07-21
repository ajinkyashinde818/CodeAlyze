#include<iostream>
using namespace std;

int main(){
 
  int r,g,b,n;
  cin >> r >> g >> b >>n;
  int sum = 0;
  int cnt = 0;
  
  int sr = n / r; // i=4 , j=2
  int sg = n / g;
  for(int i=sr;i >= 0;--i){
      for(int j=sg;j >= 0;--j){
         sum = 0;
         sum += i*r + j*g;
         if(sum <= n && (n-sum)%b == 0){
         	cnt++;
         }
      }

  }

  cout << cnt <<endl;
  
}
