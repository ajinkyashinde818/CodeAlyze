#include<stdio.h>
 
int main()
{
	int i,n,s = 0;
        int a[51],b[51],c[51];

	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		s+=b[i];
	}
	
	for(i=0;i<n-1;i++)
	scanf("%d",&c[i]);
	
	for(i=1;i<n;i++){
		if(a[i]-a[i-1]==1){
	 		s+=c[a[i-1]-1];
		}
	}
	
	printf("%d\n",s);
	return 0;
}
