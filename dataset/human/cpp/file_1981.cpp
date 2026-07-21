#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,count=0,flag=0;
  cin >> n;
  vector<long long> data(n);
  
  for(int i=0; i<n; i++){
    cin >> data.at(i);
    if(data.at(i) < 0){
      data.at(i) *= -1;
      count++;
    }else if(data.at(i) == 0){
      flag=1;
    }
  }
  
  sort(data.begin(), data.end());
  
  long long sum =0;
  for(int i=0; i<n; i++){
    sum += data.at(i);
  }
  
  if((count%2 == 0 )|| (flag==1)){
    cout << sum << endl;
  }else if(count%2 == 1){
    sum -= data.at(0);
    sum -= data.at(0);
    cout << sum << endl;
  }
}
