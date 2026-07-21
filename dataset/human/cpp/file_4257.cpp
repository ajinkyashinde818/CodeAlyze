#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>
 
#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
 
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
 
typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;
 
int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
 
const int N=1e5+19;
 
map<int,int> M,fa,sz;
int A[N],B[N];
int n,c,s,res;
Vi V;
 
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) fa[x]=y,sz[y]+=sz[x];
}
 
int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN(),s^=A[i];
	For(i,1,n+1) M[B[i]=IN()]++;
	For(i,1,n+1){
		V.pb(A[i]);
		if (!M[A[i]]) c++;else M[A[i]]--;
	}
	V.pb(s);
	if (!M[s]) c++;else M[s]--;
	if (c>1){
		puts("-1");
		return 0;
	}
	for (int i:V) fa[i]=i,sz[i]=1;
	For(i,1,n+1)
		if (A[i]!=B[i]){
			res++;
			Union(A[i],B[i]);
		}
	for (int i:V) if (fa[i]==i&&sz[i]>1&&i!=getf(s)) res++;
	printf("%d\n",res);
}
