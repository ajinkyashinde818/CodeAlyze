#include <string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <numeric>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
int main() {
  int a,b,c,n;
  cin >> a >>b >> c >>n;
  int ans=0;
  int B;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(n-i*a-j*c>=0){ 
        if((n-i*a-j*c)%b==0){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
