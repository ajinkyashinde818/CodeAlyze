#include <stdio.h>
int max(int a, int b){
	if(a>b) return a;
	else return b;
}
int min(int a, int b){
	if(a>b) return b;
	else return a;
}
int main(){
	int n;
	int i;
	int r[200000];
	int maxv,minv;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&r[i]);
	minv=r[0];
	maxv=r[1]-r[0];
	for(i=1;i<n;i++){
		maxv=max(maxv,r[i]-minv);
		minv=min(minv,r[i]);
	}
	printf("%d\n",maxv);
	return 0;
}
