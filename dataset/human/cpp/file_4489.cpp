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
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%d",b*((i%2)||(a%2==0&&i==0)));
	}
	printf("\n");
}
