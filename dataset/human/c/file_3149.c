#include<stdio.h>
int max(int a,int b){
	if(a<b)
	return b;
	else
	{
		return a;
	}
	
}
int main(){
	int k,n;
	scanf("%d%d",&k,&n);
	int a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int b[n+1];// distance bw each house
	int big=0;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		big=max(b[i],big);
	}
	b[n]=k-a[n]+a[1];
	big=max(big,b[n]);
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]>b[j]){
				int temp=b[j];
				b[j]=b[i];
				b[i]=temp;
			}
		}
	}*/
	printf("%d",k-big);

}
