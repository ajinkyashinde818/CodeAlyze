#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1e9+7;
const ll maxn=5e5+5;

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	if(n>=10){
		printf("%d",r);
	}
	else{
		printf("%d",r+100*(10-n));
	}
	return 0;
}
