#include <stdio.h>
#include<stdlib.h>
int main() {

	int a[100002]={0};
	int b[100002]={0};
	int N;
	int i,k;
	int answer=0;
	int p;

	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d %d",&a[i],&b[i]);

	for(k=N+1;k>=1;k--) {
		p=0;
		for(i=1;i<=N;i++) {
			if(a[i]<=k&&k<=b[i])
				p++;

			if(p==k) {
				answer=p-1;
				break;
			}
			else if(p==k-1) {
				answer=p;
				break;
			}
		}
		if(answer>0)
			break;
	}

	printf("%d\n",answer);
	return 0;
}
