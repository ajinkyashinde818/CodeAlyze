#include <bits/stdc++.h>
using namespace std;
 int main() {
 int N, R, G, B, count;
 cin >> R >> G >> B >> N;
 count = 0; 
 for(int r = 0; r <= N; r++){
   for(int g = 0; g <= N; g++){
     int P = N - (G*g + R*r);
     if(P >= 0 && P % B == 0){
       count++;
     }
   }
 }
   cout << count << endl;
 }
