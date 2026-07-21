#include <stdio.h>

int main(void){
	int i,j,n;
	int rt[200000],maxmin;
	int maxv,minv;
	int min;
	scanf("%d",&n);
	scanf("%d",&rt[0]);
	scanf("%d",&rt[1]);
	minv=rt[0];
	maxv=rt[1]-rt[0];
	if(rt[1]<minv) minv=rt[1];
	for(i=2;i<n;i++){
		scanf("%d",&rt[i]);
		if(rt[i]-minv>maxv){
			maxv=rt[i]-minv;
		}
		if(rt[i]<minv){
			minv=rt[i];
		}
	}
	printf("%d\n",maxv);
	return 0;
}
