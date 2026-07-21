#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
static int button[100001];
void solve(void)
{
	int n, i, i_next;
	int count=0;
	scanf("%d", &n);
	for(i=0;i<n;++i){
		int a;
		scanf("%d", &a);
		button[i]=a-1;
	}
	for(i=0; button[i]!=-1; i=i_next){
		i_next=button[i];
		button[i]=-1;
		if(i==1){
			break;
		}
		++count;
	}
	if(button[1]==-1){
		printf("%d\n", count);
	} else {
		printf("-1\n");
	}
}
int main(int argc, char **argv)
{
	solve();
	return 0;
}
