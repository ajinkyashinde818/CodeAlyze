#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  cout << setprecision(10);
  const long M = 1e9+7;
  int N;
  cin >> N;
  string S;
  cin >> S;
  long ret=S[0]=='B'?1:0;
  long c=1;
  for(int i=1; i<2*N; i++){
    if(i%2==1 ^ S[i]=='B'){
      c++;
    }else{
      c--;
      ret=(ret*(c+1))%M;
    }
  }
  if(c!=0) ret=0;
  for(int i=2; i<=N; i++) ret=(ret*i)%M;
  cout << ret << endl;
  return 0;
}
