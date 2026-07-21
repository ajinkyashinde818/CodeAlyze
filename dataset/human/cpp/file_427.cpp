#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int r,g,b,n;
	scanf("%d%d%d%d",&r,&g,&b,&n);
	int a3 = max(max(r,g),b);
	int a1 = min(min(r,g),b);
	int a2 = r+g+b-a1-a3;
	long long sum = 0;
	for(int i = 0;i*a3<=n;i++){
		int f = i*a3;
		for(int j = 0;j*a2+f<=n;j++){
			int s = j*a2;
			if( (n-f-s) % a1 == 0)sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
