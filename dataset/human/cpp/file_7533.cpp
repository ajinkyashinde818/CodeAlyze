#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
  int n;
  cin >> n;
  long long a[n];
  long long ret=0;
  for(auto& x:a){
    cin >>x;
    ret+=x;
  }
  long long out=10000000000000000;
  long long sum=0;
  for(int i=0;i<n-1;i++){
    sum+=a[i];
    out =min(out,abs(ret-2*sum));
  }
  cout << out << endl;
}
