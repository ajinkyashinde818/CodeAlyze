#include<stdio.h>
int main(){
    int n,i,j,max,min;
    scanf("%d",&n);
    int r[n+1];
    for(i=0;i<n;i++)
    scanf("%d",&r[i]);
    min=r[0];
    max=r[1]-r[0];
    for(i=1;i<n;i++){
    	if(r[i-1]<min)
        min=r[i-1];
    	if(r[i]-min>max)
    	max=r[i]-min;  
    }
    printf("%d\n",max);
    return 0;
}
