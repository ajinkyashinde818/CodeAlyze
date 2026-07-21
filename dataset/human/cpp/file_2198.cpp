#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int64_t n;
  cin>>n;
  std::vector<int64_t> a(n);
  int64_t cnt=0,sum=0;
  for (int i = 0; i < n; ++i)
  {
    int64_t tmp;
    cin>>tmp;
    a[i]=abs(tmp);
    sum+=abs(a[i]);
    cnt+=(tmp<0)? 1:0;
  }

  if(cnt%2!=0) sum-=2*(*min_element(a.begin(), a.end()));
  cout<<sum;
}
