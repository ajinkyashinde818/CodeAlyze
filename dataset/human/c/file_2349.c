#include <stdio.h>

int main(void) {
    int n,k,s,a[100000],i,j,l;
    scanf("%d %d %d",&n,&k,&s);
        for(i=0;i<k;i++) a[i]=s;
    if(s<1000000000)    for(i=k;i<n;i++) a[i]=s+1;
    else for(i=k;i<n;i++) a[i]=1;
    for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}
