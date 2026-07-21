#include <stdio.h>
int main(void)
{
   
       	int n,i;
	
    scanf("%d",&n);

    int a[n],b[n],c[n-1];

    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) scanf("%d",&b[i]);
    for(i=0;i<n-1;i++) scanf("%d",&c[i]);
    
    int t = b[a[0]-1];
    for(i=1;i<n;i++){
        t+=b[a[i]-1];
        if(a[i]-1==a[i-1]) t+=c[a[i-1]-1];
    }
    printf("%d",t);
    return 0;
}
