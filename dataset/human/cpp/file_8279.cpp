#include <bits/stdc++.h>
using namespace std;

int main() {
 int N, M;
 cin >> N >> M;
 
 vector <vector<char>> A(N,vector<char>(N));
 vector <vector<char>> B(M,vector<char>(M));
  
 for (int i = 0; i < N; i++){
   for (int j = 0; j < N; j++)
     cin >> A.at(i).at(j);
 }
 for (int i = 0; i < M; i++){
   for (int j = 0; j < M; j++)
     cin >> B.at(i).at(j);
 }
 bool answer = false;
 for(int x = 0; x <= N-M;x++){
   for(int y = 0; y <= N-M;y++){
     bool match = true;
 		for (int i = 0; i < M; i++){
    	  for (int j = 0; j < M; j++){
    		if (A.at(i+x).at(j+y) != B.at(i).at(j))
          	match = false;
          }
      }
     if(match) answer = true;
    }
 }
 if(answer) cout << "Yes" << endl;
 else cout << "No" << endl;
}
