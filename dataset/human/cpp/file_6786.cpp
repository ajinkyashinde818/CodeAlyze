// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<random>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
struct val{
  ll n,c;
  bool mk;
};
const val INV = val{0,0,true};
void next_que(queue<val> &que,val &use){
  if(que.empty()){
    use = INV;
  }else{
    use = que.front();
    que.pop();
  }
}
void timers(chrono::system_clock::time_point start,double tl){
  double time;
  chrono::system_clock::time_point now;
  ll n;
  cin >> n;
  vector<ll> a(n),b(n),ans(n,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  bool can = false;
  map<ll,ll> mp;
  for(int i=0;i<n;i++){
    cin >> b[i];
    mp[b[i]]++;
  }
  vector<val> mpr;
  for(auto itr=mp.rbegin();itr!=mp.rend();itr++){
    mpr.push_back(val{itr->first,itr->second,false});
  }
  while(!can){
    val fi,se;
    queue<val> que;
    for(auto itr=mpr.begin();itr!=mpr.end();itr++){
      if(itr->n<=a.back()&&itr->n>=a.front()){
        que.push(val{itr->n,itr->c,false});
      }
    }
    for(auto itr=mpr.begin();itr!=mpr.end();itr++){
      if(itr->n>a.back()||itr->n<a.front()){
        que.push(val{itr->n,itr->c,true});
      }
    }
    next_que(que,fi);
    next_que(que,se);
    for(int i=0;i<n;i++){
      if(fi.n!=a[i]){
        ans[i] = fi.n;
        fi.c--;
        if(fi.c==0){
          fi = se;
          next_que(que,se);
        }
      }else{
        if(se.n==0){
          break;
        }
        ans[i] = se.n;
        se.c--;
        if(se.c==0){
          next_que(que,se);
        }
      }
    }
    if(ans.back()!=0){
      can = true;
      break;
    }
    auto tmp = mpr.back();
     std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
    shuffle(mpr.begin(),mpr.end(),engine);
    now = chrono::system_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(now-start).count();
    if(time>=tl) break;
  }
  if(!can){
    cout <<"No\n";
    return;
  }
  cout << "Yes\n";
  for(int i=0;i<n;i++){
    cout << ans[i]<<" ";
  }
  cout << endl;
}
signed main(){
  init_io();
  timers(chrono::system_clock::now(),1800);
}
