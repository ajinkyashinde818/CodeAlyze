#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, l;
ll f(ll n){
  return n & -n;
}
struct Trie{
  struct Node{
    Node* ch[2];
    bool end;
    Node(){
      ch[0] = ch[1] = 0;
      end = 0;
    }
  };
  Node* root;
  Trie(){
    root = new Node();
  }
  void add(string s){
    Node* cur = root;
    for(int i = 0;i < s.size();i++){
      if(cur -> ch[s[i] - '0'] == 0){
        cur -> ch[s[i] - '0'] = new Node();
      }
      cur = cur -> ch[s[i] - '0'];
    }
    cur -> end = 1;
  }
  ll solve(Node* nd, int d = 0){
    if(nd -> end)
      return 0;
    ll res = 0;
    if(nd -> ch[0])
      res ^= solve(nd -> ch[0], d + 1);
    else
      res ^= f(l - d);
    if(nd -> ch[1])
      res ^= solve(nd -> ch[1], d + 1);
    else
      res ^= f(l - d);
    return res;
  }
};
vector<string> arr;
int main()
{

//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//  int f[101];
//  f[0] = 1;
//  for(int i = 1;i < 101;i++){
//    vector<int> arr;
//    int x = 0;
//    for(int j = 1;j <= i;j++){
//      x ^= f[i - j];
//      arr.push_back(x);
//    }
//    sort(arr.begin(), arr.end());
//    for(int j = 1;j < 102;j++){
//      if(arr[j - 1] != j){
//        cout << j << ' ' << ((i + 1) & -(i + 1)) << endl;
//        f[i] = j;
//        break;
//      }
//    }
//  }
//
//
//  return 0;
  Trie tr;
  cin >> n >> l;
  arr.resize(n);
  for(int i = 0;i < n;i++){
    cin >> arr[i];
//    if(i == 1)return 0;
    tr.add(arr[i]);
  }
  cout << (tr.solve(tr.root) ? "Alice" : "Bob");
  return 0;
}
