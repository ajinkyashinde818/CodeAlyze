#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int S[100005],T[100005],n,ans,sum;
int A[100005],B[100005],sa,sb;
int fa[100005],Do[200005];
int gg(){printf("-1");return 0;}
int ask(int x){if(fa[x]==x)return x;return fa[x]=ask(fa[x]);}
void unite(int x,int y){fa[x]=y;}
int main(){
//  freopen("duliu.in","r",stdin);
//  freopen("duliu.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]),sa^=A[i];A[n+1]=sa;
    for(int i=1;i<=n;i++)scanf("%d",&B[i]),sb^=B[i];B[n+1]=sb;
    memcpy(S,A,sizeof A);memcpy(T,B,sizeof B);
    n++;sort(S+1,S+1+n);sort(T+1,T+1+n);
    for(int i=1;i<n;i++)if(S[i]!=T[i])return gg();
    for(int i=1;i<=n;i++)
    	if(A[i]!=B[i]||(i==n)){
			Do[++sum]=A[i];
			Do[++sum]=B[i];
			if(i<n)ans++;
		}
	if(ans==0)return printf("0"),0;
	sort(Do+1,Do+1+sum);
	sum=unique(Do+1,Do+sum+1)-Do-1;
	for(int i=1;i<=sum;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		if(A[i]!=B[i]){
			A[i]=lower_bound(Do+1,Do+1+sum,A[i])-Do;
			B[i]=lower_bound(Do+1,Do+1+sum,B[i])-Do;
			unite(ask(A[i]),ask(B[i]));
		}
	}
	for(int i=1;i<=sum;i++)ans+=(fa[i]==i);
	printf("%d",ans-1);
}
/*
3
1 2 3
1 3 2
*/
/*
4
1 4 2 6
1 2 4 6
*/
/*
10
1 3 3 9 4 5 1 6 4 0
4 1 3 9 10 4 3 1 6 5
*/
/*
5
1 2 4 8 0
2 1 15 8 4
*/
/*
10
1 2 3 4 4 5 6 7 8 12
2 1 4 3 4 0 5 6 7 8
*/
/*
10
1 2 3 4 5 6 7 8 9 10
10 1 2 3 4 5 6 7 8 9
*/
/*
10
1 2 3 4 5 6 7 8 9 10
2 1 4 3 6 5 8 7 10 9
*/
/*
9
1 2 3 4 5 6 7 8 9
9 1 2 3 4 5 6 7 8
*/
