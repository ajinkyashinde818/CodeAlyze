#include<stdio.h>
int main(void)
{
    int n,a[100000],flg=0,i,w,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	}
	w=0;
	j=1;
	while(1){
	    j=a[j];
		w++;
		if(j==2) break;
		if(w>n){
		    w=-1;
			break;
		}
	}
	printf("%d\n",w);
	return 0;
}
