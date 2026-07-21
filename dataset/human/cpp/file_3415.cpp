using ll=long long;using ull=unsigned long long;
#include<limits>
namespace pcl{template<typename T>constexpr T TNF=std::numeric_limits<T>::max()/2;constexpr int INF=TNF<int>;constexpr ll LNF=TNF<ll>;constexpr double DNF=TNF<double>;constexpr double EPS=1e-8;constexpr int P7=1'000'000'007;constexpr int DX[]={1,0,-1,0,1,1,-1,-1};constexpr int DY[]={0,1,0,-1,-1,1,1,-1};}
#include<algorithm>
#include<cmath>
#include<iostream>
namespace pcl{template<typename T>void updmax(T&a,T const&b){a=std::max(a,b);}template<typename T>void updmin(T&a,T const&b){a=std::min(a,b);}template<typename T,typename U,typename V>bool in_range(T const&begin,U const&mid,V const&end){return begin<=mid&&mid<end;}template<typename T,typename U,typename V>bool in_range(T const&begin,std::initializer_list<U>list,V const&end){auto p=std::minmax_element(list.begin(),list.end());return begin<=*p.first&&*p.second<end;}template<typename T,typename U,typename V>bool in_range_strict(T const&begin,std::initializer_list<U>list,V const&end){if(!std::is_sorted(list.begin(),list.end()))return false;return in_range(begin,list,end);}template<typename T>inline T cget(){T x;std::cin>>x;return x;}}
#include<iostream>
#include<vector>
namespace pcl{template<typename T>std::ostream&operator<<(std::ostream&os,std::vector<T>const&v){os<<'[';for(size_t i=0;i<v.size();i++){if(i!=0)os<<",";os<<v[i];}os<<']';return os;}template<typename T>std::istream&operator>>(std::istream&is,std::vector<T>&v){for(size_t i=0;i<v.size();i++)is>>v[i];return is;}}
#include<bits/stdc++.h>
using namespace std;using namespace pcl;int main(){int N;cin>>N;vector<ll>A(N);cin>>A;sort(A.rbegin(),A.rend(),[](ll a,ll b){return abs(a)<abs(b);});for(int i=0;i<N-1;i++){if(A[i]<0)A[i]*=-1,A[i+1]*=-1;}cout<<accumulate(A.begin(),A.end(),0ll)<<endl;}
