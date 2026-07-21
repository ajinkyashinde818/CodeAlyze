#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int t[1100][1100];
int main(){
	int a;scanf("%d",&a);
	for(int i=1;i<11000;i++){
		if(i*(i-1)/2==a){
			printf("Yes\n");
			printf("%d\n",i);
			int cnt=0;
			for(int j=0;j<i;j++){
				for(int k=0;k<j;k++){
					cnt++;
					t[j][k]=t[k][j]=cnt;
				}
			}
			for(int j=0;j<i;j++){
				printf("%d",i-1);
				for(int k=0;k<i;k++){
					if(j==k)continue;
					printf(" %d",t[j][k]);
				}printf("\n");
			}
			return 0;
		}
	}
	printf("No\n");
}
