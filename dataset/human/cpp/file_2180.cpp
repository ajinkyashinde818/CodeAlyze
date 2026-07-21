#include <string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;

int main() {
 long long int n;
  cin >> n;
  vector<long long int> vec(n);
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
 long long int count=0;
  for(int i=0;i<n;i++){
    if(vec.at(i)<0){
      count++;
      vec.at(i)=vec.at(i)*-1;
    }
  }
  sort(vec.begin(), vec.end());
 long long int ans=0;
  for(int i=0;i<n;i++){
    ans+=vec.at(i);
  }
  if(count%2==0){
    cout << ans << endl;
  }
  else{
    cout << ans-vec.at(0)*2 << endl;
  }
}
