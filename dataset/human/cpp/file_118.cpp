#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<tuple>
#include<vector>
#include<map>
#include<numeric>
#include<limits>
#include<type_traits>
using namespace std;

int main(void){
  long long int R, G, B, N;
  long long int ans = 0;
  cin >> R >> G >> B >> N;
  for(long long int r = 0; r <= N / R; r++){
    for(long long int g = 0; g <= N / G; g++){
      long long int temp = N - R*r - G*g;
      if(temp >= 0 && temp % B == 0){
        ans++;
       // cout << r << " " << g << " " << temp / B << endl;
      }
    }
  }
  cout << ans << endl;
}
