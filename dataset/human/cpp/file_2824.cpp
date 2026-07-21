#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  vector<long long>B1(N);
  vector<long long>B2(N);
  B1.at(0)=A.at(0);
  B2.at(0)=(-1)*A.at(0);
  for(int i=0;i<N-2;i++){
    B1.at(i+1)=max(B1.at(i)+A.at(i+1),B2.at(i)-A.at(i+1));
    B2.at(i+1)=max(B2.at(i)+A.at(i+1),B1.at(i)-A.at(i+1));
  }
  B1.at(N-1)=B1.at(N-2)+A.at(N-1);
  B2.at(N-1)=B2.at(N-2)-A.at(N-1);
  cout<<max(B1.at(N-1),B2.at(N-1))<<endl;
}
