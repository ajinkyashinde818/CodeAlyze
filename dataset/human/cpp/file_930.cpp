#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int r,g,b,k;

  cin >> r >> g >> b >> k;
  int temp1, temp2;
  int num = 0;
  for(int x=0;x<k+1;x++){
    if(x*r > k)
      continue;
    temp1 = k - r*x;
    for(int y=0;y<temp1+1;y++){
      if(y*g > temp1)
        continue;
      temp2 = temp1 - g*y;
      if (temp2 % b == 0){ 
          //cout << "x:"<<x<< " y:" << y << " z:" << z << endl;
          //cout << '\n';
          num++;
      }   
    }   
  }
  cout <<  num << endl;
}
