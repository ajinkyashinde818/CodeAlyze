#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  
  vector<int> ok(N+1);
  
  vector<int>::iterator pos;
  for(int i=0; i<N; i++){
    int a, b;
    pos = lower_bound(A.begin(),A.end(),B[i]);
    a = distance(A.begin(),pos);
    pos = upper_bound(A.begin(),A.end(),B[i]);
    b = distance(A.begin(),pos);
    b--;
    if(i < a){
      ok[0]++;
      ok[i+N-b]--; //i+N-b回でゾーン突入
      ok[i+N-a+1]++; //i+N-a回でゾーン脱出
      ok[N]--;
    }
    else if(i >= a && i <= b){
      ok[i-a+1]++;
      ok[N-(b-i)]--;
    }
    else{
      ok[0]++;
      ok[i-b]--;
      ok[i-a+1]++;
      ok[N]--;
    }
  }
  
  
  for(int i=0; i<N; i++){
    ok[i+1] += ok[i];
  }
  
  for(int i=0; i<N; i++){
    if(ok[i] == N){
      cout << "Yes" << endl;
      for(int j=0; j<N; j++){
        cout << B[(i+j)%N] << endl;
      }
      return 0;
    }
  }
  cout << "No" << endl;
}
