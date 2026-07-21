#include<stdio.h>

int main(void)
{
    int n, sum=0;
    scanf("%d", &n);
    int a[n], b[n], c[n-1]; 
  
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
  	for(int i=0; i<n; i++) scanf("%d",&b[i]);
	for(int i=0; i<n-1; i++) scanf("%d",&c[i]);

  	for(int i=0; i<n; i++)
  	{
   		sum += b[a[i]-1];
    	if(a[i] == a[i-1] + 1) sum += c[a[i-1]-1];
    }
  
 	printf("%d", sum);
  
  	return 0;
}
