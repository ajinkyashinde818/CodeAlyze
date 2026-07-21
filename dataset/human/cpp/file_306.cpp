#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int GCD(int a, int b){
   return b ? GCD(b, a%b) : a;
}

int LCM(int a, int b){
   return (a * b)/(GCD(a, b));
}

int main(){
   int R, G, B, N;
   cin >> R >> G >> B >> N;

   int ans = 0;
   for(int g = 0; g <= 3000; g++){
      for(int b = 0; b <= 3000; b++){
         int sum = g*G + b*B;
         if(sum <= N){
            int others = N - sum;
            if(others % R == 0){
               ans++;
            }
         }
      }
   }

   cout << ans << endl;

   return 0;
}
