#include <bits/stdc++.h>

 using namespace std;

 int main() {
   int N, M, i, j, k, l;
   bool match;
   string ans;
   cin >> N >> M;

   vector<vector<char>> A(N, vector<char>(N));
   vector<vector<char>> B(M, vector<char>(M));

   for (i = 0; i < N; i++) {
     for (j = 0; j < N; j++) {
       cin >> A.at(i).at(j);
     }
   }

   for (i = 0; i < M; i++) {
     for (j = 0; j < M; j++) {
       cin >> B.at(i).at(j);
     }
   }

   ans = "No";

   for (i = 0; i < N - M + 1; i++) {
     for (j = 0; j < N - M + 1; j++) {
       match = true;
       for (k = 0; k < M; k++) {
         for (l = 0; l < M; l++) {
           if (A.at(i + k).at(j + l) != B.at(k).at(l)) {
             match = false;
           }
         }
       }
       if (match == true) ans = "Yes";
     }
   }
   cout << ans << endl;

 }
