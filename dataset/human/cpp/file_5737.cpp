#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
struct node{
	node* son[2];
	bool hv;
	node(){
		hv=false;
		son[0]=son[1]=NULL;
	}
};
vector<ll> sol;
string S;
ll T;
void insert(node*& cur,int pos){
	if(cur==NULL)cur=new node;
	if(pos==S.length())cur->hv=true;
	else insert(cur->son[S[pos]-'0'],pos+1);
}
void dfs(node*& cur,int dep){
	if(dep>T)return;
	if(cur==NULL){
		sol.push_back(T-dep);
		return;
	}
	if(cur->hv)return;
	dfs(cur->son[0],dep+1);
	dfs(cur->son[1],dep+1);
}
ll grundy(ll x){
	return (x+1LL)&(-x-1LL);
}
int main(){
	int n;
	node* root=NULL;
	cin>>n>>T;
	rep(k,n){
		cin>>S;
		insert(root,0);
	}
	dfs(root,0);
	ll dat=0LL;
	rep(k,sol.size())dat^=grundy(sol[k]);
	cout<<(dat==0LL?"Bob\n":"Alice\n");
	return 0;
}
