#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	if(n>=10)printf("%d",r);
	else {
		printf("%d\n",r+100*(10-n));
	}
	return 0;
}
