#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,s=0;
  int cnt;
  cin >> N;
  vector<double> a(N);
  vector<double> b(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
    if(a.at(i)<0){
      b.at(i) = -a.at(i);
      cnt ++;
    }
    else{
      b.at(i)= a.at(i);
    }
  }
  sort(b.begin(),b.end());
  for(int j=0;j<N;j++){
    s += b.at(j);
  } 
  if(cnt % 2 ==0){
    cout <<fixed << setprecision(0) << s << endl;
  }
  else
   cout << fixed << setprecision(0) <<s-2 * b.at(0) << endl;
}
