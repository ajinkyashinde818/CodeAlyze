#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

using ll = long long;

struct Heap {
  Heap *l, *r;
  long double val;
  int pos;
  Heap(long double val, int pos) : val(val), pos(pos) {
    l = r = nullptr;
  }
};
Heap  *root;
Heap *meld(Heap *a, Heap *b) {
  if(a == nullptr) return b;
  if(b == nullptr) return a;

  if(a->val > b->val) swap(a, b);
  a->r = meld(a->r, b);
  swap(a->l, a->r);

  return a;
}
void push(Heap x){
  
  Heap *p = new Heap(x);
  root = meld(root, p);
}
Heap top()
{
  return (*root);
}
void pop()
{
  Heap *p = root;
  root = meld(root->r, root->l);
  delete p;
}



long double calc(long double x1, long double y1, long double x2, long double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    
    long double xs,ys,xt,yt; cin >>xs>>ys>>xt>>yt;
    int N;
    cin >> N;
    
    vector<long double> x,y,r;
    x.push_back(xs);
    y.push_back(ys);
    r.push_back(0);
    for(int i = 0; i<N; i++){
        int a, b, c; cin>>a>>b>>c;
        x.push_back(a);
        y.push_back(b);
        r.push_back(c);
    }
    x.push_back(xt);
    y.push_back(yt);
    r.push_back(0);
    
    
    push(Heap(0, 0));
 
    vector<long double> dist(N+3, (1LL<<61));
 
    dist[0] = 0;
    while(root){
        Heap xx = top();
        pop();
        long double c = xx.val, pos = xx.pos;
        if(dist[pos] < c) continue;
 
        for(int i=0; i<x.size(); i++){
            if(i == pos) continue;
            
            long double d = calc(x[pos], y[pos], x[i], y[i]);
            if(r[pos] + r[i] >= d){
                if(dist[i] > dist[pos]){
                    dist[i] = dist[pos];
                    push(Heap(dist[pos], i));
                }
            }else{
                long double g = d - r[pos]-r[i];
                if(dist[i] > dist[pos] + g){
                    dist[i] = dist[pos] + g;
                    push(Heap(dist[i], i));
                }
            }
        }
    }
    cout << dist[x.size()-1] << endl;
    return 0;
}
