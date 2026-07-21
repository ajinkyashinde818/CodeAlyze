#include<iostream>
#include<iterator>
#include<numeric>
#include<vector>

int main(){
  auto r = 0LL;
  long long n, c; std::cin >> n >> c;
  std::vector<std::pair<long long, long long>> v(n);
  for(auto i=0; i<n; ++i){
    long long xx, vv; std::cin >> xx >> vv;
    v[i] = {xx, vv};
  }
  std::vector<long long> y(n+2);
  y[0] = 0;
  auto s = 0LL;
  for(auto i=0; i<n; ++i){
    s += v[i].second;
    y[i+1] = s - v[i].first;
  }
  y[n+1] = s - c;
  std::partial_sum(y.begin(), y.end(), y.begin(), [](long long a, long long b){return std::max(a, b);});
  // std::copy(y.begin(), y.end(), std::ostream_iterator<long long>(std::cerr, " "));
  // std::cerr << '\n';  
  std::vector<long long> xdx(n+2);
  xdx[0] = 0;
  s = 0LL;
  for(auto i=0; i<n; ++i){
    s += v[n-i-1].second;
    xdx[i+1] = s - 2*(c - v[n-i-1].first);
  }
  xdx[n+1] = s - 2*c;
  std::partial_sum(xdx.begin(), xdx.end(), xdx.begin(), [](long long a, long long b){return std::max(a, b);});
  // std::copy(xdx.begin(), xdx.end(), std::ostream_iterator<long long>(std::cerr, " "));
  // std::cerr << '\n';
  for(auto i=0; i<n+1; ++i)
    r = std::max(r, y[i]+xdx[n-i]);
  // std::cerr << r << '\n';
  std::vector<long long> ydy(n+2);
  ydy[0] = 0;
  s = 0LL;
  for(auto i=0; i<n; ++i){
    s += v[i].second;
    ydy[i+1] = s - 2*v[i].first;
  }
  ydy[n+1] = s - 2*c;
  std::partial_sum(ydy.begin(), ydy.end(), ydy.begin(), [](long long a, long long b){return std::max(a, b);});
  std::vector<long long> x(n+2);
  x[0] = 0;
  s = 0LL;
  for(auto i=0; i<n; ++i){
    s += v[n-i-1].second;
    x[i+1] = s - (c - v[n-i-1].first);
  }
  x[n+1] = s - c;
  std::partial_sum(x.begin(), x.end(), x.begin(), [](long long a, long long b){return std::max(a, b);});
  for(auto i=0; i<n+1; ++i)
    r = std::max(r, ydy[i]+x[n-i]);  
  std::cout << r << '\n';
}
