#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
char A[60][60];
char B[60][60];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",A[i]);
	for(int i=0;i<b;i++)scanf("%s",B[i]);
	for(int i=0;i<=a-b;i++)for(int j=0;j<=a-b;j++){
		bool ok=true;
		for(int k=0;k<b;k++)for(int l=0;l<b;l++){
			if(B[k][l]!=A[i+k][j+l])ok=false;
		}
		if(ok){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");
}
