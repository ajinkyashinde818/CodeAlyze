#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long int A[N];
  int count=0;
  long long int min=1000000005;
  long long int sum=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if (A[i]<0) {
      count++;
      A[i]*=-1;
    }
    if(min>A[i]){
      min = A[i];
    }
    sum+=A[i];
  }
  if (count%2==1){
    sum-=2*min;
  }
  cout << sum << endl;
}
