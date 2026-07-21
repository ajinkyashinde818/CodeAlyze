#include<iostream>
using namespace std;
int main(){
  int r,g,b,n,num,cnt=0;
  cin >> r >> g >> b >> n;
  for(int i=0;i*r<=n;i++){
    for(int j=0;j*g+i*r<=n;j++){
      num =n-(i*r+g*j);
      if(num%b==0){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
