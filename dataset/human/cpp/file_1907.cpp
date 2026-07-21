#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<bitset>
#include<cmath>
#include<sstream>
using namespace std;
string htox(){
  
  
}

int main(){
  int num;
  cin >> num;
  for(int k=0;k<num;k++){
    string N;
    bitset<32> b;
    cin >> N;
    for(int i=0;i<8;i++){
      int n;
      if(N[i]>='a')
	n=N[i]-'a'+10;
      else
	n=N[i]-'0';
      for(int j=0;j<4;j++)
	b.set(31-(i*4+j),n&(int)pow(2,3-j));
    }
    if(b[31])
      cout << '-';
    long long int r=0;
    for(int i=7;i<31;i++)
      if(b[i])
	r+=powl(2,i-7);
    cout << r;
    r=0;
    for(int i=0;i<=6;i++)
   if(b[i])
     r+=pow(0.5,7-i)*pow(10,10);
    int j=9;
    cout << '.';
    if(r!=0)
      while(r<pow(10,j)){
	j--;
	cout << 0;
      }
    while(r%10==0 && r!=0)
      r/=10;
      cout << r;
    cout << endl;
  }
  return 0; 
}
