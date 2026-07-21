#include <iostream>
#include <bitset>
#include <cmath>
#include <iomanip>
using namespace std;
string syodu(int s){
  int ret = 78125*s;
  while(ret % 10 == 0)ret/=10;
  string zero;
  if(s == 1)zero = "00";
  else if(s <= 12)zero = "0";
  return zero+to_string(ret);
}
int main(){
  int q;cin>>q;
  for(int i = 0; q > i; i++){
    long long ans = 0;
    int syosu = 0;
    bool seihu = true;
    char b[8];for(int j = 0; 8 > j; j++)cin>>b[j];
    for(int j = 0; 8 > j; j++){
      bitset<4>tm = b[j];
      if(b[j] >= 'a'){
        tm = 10+(b[j]-'a');
      }
      if(tm[3]){
        if (j == 0) {
          seihu = false;
        }else if(j <= 6){
          ans += pow(2,(6-j)*4);
        }else{
          syosu+=8;
        }
      }
      if(tm[2]){
        if(j <= 5){
          ans += pow(2,((5-j)*4+3));
        }else{
          if(j == 6)syosu+=64;
          if(j == 7)syosu+=4;
        }
      }
      if(tm[1]){
        if(j <= 5){
          ans += pow(2,((5-j)*4+2));
        }else{
          if(j == 6)syosu += 32;
          if(j == 7)syosu += 2;
        }
      }
      if(tm[0]){
        if(j <= 5){
          ans += pow(2,((5-j)*4+1));
        }else{
          if(j == 6)syosu += 16;
          if(j == 7)syosu += 1;
        }
      }
      
    }
    if(!seihu)cout << '-';
    if(syosu == 0){
      cout << fixed << ans << ".0" << endl;
    }else{
      cout << fixed << ans << "." << syodu(syosu)  << endl;
    }
  }
}
