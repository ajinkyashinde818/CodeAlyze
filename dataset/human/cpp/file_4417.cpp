#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int A[110000];
int B[110000];
int p[110000];
int q[110000];
int UF[110000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",A+i);
	}
	for(int i=0;i<a;i++){
		scanf("%d",B+i);
	}
	int S=0;
	int T=0;
	for(int i=0;i<a;i++){
		S^=A[i];
		T^=B[i];
	}
	A[a]=S;B[a]=T;
	a++;
	for(int i=0;i<a;i++){
		p[i]=A[i];q[i]=B[i];
	}
	std::sort(p,p+a);std::sort(q,q+a);
	for(int i=0;i<a;i++){
		if(p[i]!=q[i]){
			printf("-1\n");return 0;
		}
	}
	for(int i=0;i<a;i++)UF[i]=-1;
	int ret=0;
	for(int i=0;i<a-1;i++){
		if(A[i]!=B[i]){
			ret++;
			UNION(lower_bound(p,p+a,A[i])-p,lower_bound(p,p+a,B[i])-p);
		}
	}
	for(int i=0;i<a;i++)if(i==0||p[i]!=p[i-1])if(UF[i]<-1)ret++;
	if(UF[FIND(lower_bound(p,p+a,A[a-1])-p)]!=-1){
		ret--;
	}
	printf("%d\n",ret);
}
