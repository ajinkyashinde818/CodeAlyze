#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAX(x,y) ((x)>(y)?(x):(y))
int maxx,maxi,n,arr[55];
int main(){
	int i;
	scanf("%d",&n);
	maxx=0;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(abs(arr[i])>=abs(maxx)){
			maxx=arr[i];
			maxi=i;			
		}
	}
	printf("%d\n",2*n-1);
	for(i=1;i<=n;i++)	printf("%d %d\n",maxi,i);
	if(maxx<0){
		for(i=n;i>=2;i--)	printf("%d %d\n",i,i-1);
	}else{
		for(i=1;i<n;i++)	printf("%d %d\n",i,i+1);
	}
	return 0;
}
