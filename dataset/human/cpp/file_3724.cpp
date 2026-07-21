#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector <int> a = vector <int> (n);
  int m=0;
  int zero =0;
  long long ans =0;
  const int INF = 1001001001;
  
  //入力と、マイナスの数を数える
  for(int i=0; i <n; i++){
    cin>> a.at(i);
    ans+=std::abs(a.at(i));
    if(a.at(i) < 0){
        m++;
    } else if(a.at(i) == 0){
        zero = -1;
    }
  }
  int mini = INF;
  for(int i =0; i < n; i ++){
      mini = min(mini,std::abs(a.at(i)));
  }
 


  if(zero == -1||m%2==0){

    cout << ans<<endl;
  }else {
cout << ans -2*mini << endl;
  }
}
