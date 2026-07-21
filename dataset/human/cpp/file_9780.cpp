#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  int j=0;
  vector<int> vec(26);
  cin >> N >> S ;
  
  for (char c='a'; c<='z' ; c++){
    vec.at(j)=1;
    for(int i=0; i<N; i++){
      if( S.at(i) == c){
        vec.at(j)++;
      }
    }
    j++;
  }
  int m;
  long K=1;
  for (int i=0; i<26; i++){
    K *= vec.at(i);
    K = K%1000000007;
  }
  cout << K-1 << endl;

}
