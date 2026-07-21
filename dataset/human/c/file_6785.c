#include<stdio.h>
#include<math.h>

int search(int k,int n,int A[]){
	int l=1;
	int r=pow(10,9);
	double x;
	int count;
	int i;

while (r>l){
x=floor((r-l)/2)+l;
    count=0;
	for(i=0;i<n;i++){
	     count+=ceil(A[i]/x)-1;
	}
	if(count<=k){
      r=x;//どちらかは＋１にしておく
	}
	else
	{
		l=x+1;
		if(r==l) x+=1;//最後がNoだと＋１がいる場合分け
	}
}
	
return x;
}

int main(void){
int n,k;
int i;
int ans;
scanf("%d %d",&n,&k);

int A[n];
for(i=0;i<n;i++)
   scanf("%d",&A[i]);



ans=search(k,n,A);
printf("%d\n",ans);



	return 0;
}
