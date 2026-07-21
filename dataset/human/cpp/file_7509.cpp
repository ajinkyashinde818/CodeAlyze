#include <bits/stdc++.h>
using namespace std;
 


int main() {
 

  int64_t n;
  cin>>n;

  vector<int64_t> a(n);
  int64_t sum=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    sum+=a.at(i);
  }

  int64_t sum_sunuke=0;
  int64_t sum_raccoon=sum;
  int64_t min_diff=10000000000;
  for(int i=0;i<n-1;i++){
    sum_sunuke+=a.at(i);
    sum_raccoon-=a.at(i);
    min_diff = min(min_diff,abs(sum_raccoon-sum_sunuke));
  }

  cout<<min_diff<<endl;

	return 0;
}
