#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct data{
  int left;
  int right;
  int depth;
  data(int a=-1,int b=-1,int c=-1){
    left=a;
    right=b;
    depth=c;
  }
};

data t[1000000];
int sz=1;

ll N,L;
ll ans=0;

void dfs(int pos,ll depth=0){
  if(pos==-1){
    ll d=(L-depth)+1;
    ans^= (  d&-d );
    return;
  }
  if(depth==L)return;
  if( t[pos].left == t[pos].right )return;
  dfs(t[pos].left,depth+1);
  dfs(t[pos].right,depth+1);
}



int main(){

  vector<int> a(100005);
  /*
  for(int i=0;i<=50;i++){
    set<int> st;
    st.insert(0);
    
    int tmp=0;
    for(int j=i-1;j>=0;j--){
      tmp^=a[j];
      st.insert(tmp);
    }

    int p=0;
    while(st.count(p)==1)p++;
    int k=i+1;
    cout<<i<<' '<<p<<' '<< (k&-k) <<endl;

    a[i]=p;
  }
  */
  t[0]=data(-1,-1,0);
  
  cin>>N>>L;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    
    int pos=0;  
    for(char ch:s){
      int next;
      if(ch=='0'){
        if(t[pos].left==-1){
          t[pos].left = sz;
          sz++;
        }
        next=t[pos].left;
      }else{
        if(t[pos].right==-1){
          t[pos].right = sz;
          sz++;
        }
        next=t[pos].right;
      }
      t[next].depth=t[pos].depth+1;
      pos=next;
    }
  }

  dfs(0);

  cout<< (ans ? "Alice" : "Bob" )<<endl;
  return 0;
}
