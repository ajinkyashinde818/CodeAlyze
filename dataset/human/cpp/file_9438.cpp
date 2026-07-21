#include <bits/stdc++.h>
using namespace std;

int main() {
string ans="No";
	int N,M;
	cin>>N>>M;
  vector<string> A(N),B(M);
	for(int i=0; i<N; i++){
      cin>>A.at(i);}
  for(int i=0; i<M; i++){
      cin>>B.at(i);}
  
  for(int i=0; i<N-M+1; i++){
    for(int k=0; k<N-M+1;k++){
    if(A.at(i).at(k)==B.at(0).at(0)){
         for(int j=0; j<M; j++){
              for(int l=0; l<M; l++){
           if(A.at(i+j).at(k+l)!=B.at(j).at(l)) goto next;}}
    ans="Yes";goto last;  next :  ans=ans;}}}    
      last:
      cout<<ans<<endl;
}
