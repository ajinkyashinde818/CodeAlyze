#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
#include <limits.h>
using namespace std;
typedef long long LL;

int n;
vector<int> vc[1000];

int main() {
	scanf("%d",&n);
	n<<=1;
	//printf("n=%d\n",n);
	int m=0;
	for(int i=1;i<=n;i++) {
		if(n%i==0) {
			if(i>=n/i) break;
			if(n/i-i==1) {
				m=n/i;break;
			}
		}
	}
	if(m==0) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	int x=0;
	for(int i=0;i<m;i++) {
		vc[i].resize(m-1);
	}
	for(int i=0;i<m-1;i++) {
		for(int j=i;j<m-1;j++) {
			x++;
			vc[i][j]=x;
		}
	}
	x=0;
	for(int i=0;i<m-1;i++) {
		for(int j=i+1;j<m;j++) {
			x++;
			vc[j][i]=x;
		}
	}
	printf("%d\n",m);
	for(int i=0;i<m;i++) {
		printf("%d",m-1);
		for(int j=0;j<m-1;j++) {
			printf(" %d",vc[i][j]);
		}
		printf("\n");
	}
}
