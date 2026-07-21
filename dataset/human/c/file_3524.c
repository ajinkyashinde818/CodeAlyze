#include<stdio.h>

int main(void){
	int n,i;
	scanf("%d",&n);
	
	int a[n];
	long long int  k;
	scanf("%lld",&k);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int town[n][2],root[n+1];
	
	for(i=0;i<n;i++){
		town[i][0]=0;
	}
	
	for(i=0;;i++){
		if(i==0){
			root[0]=a[0];
			town[root[0]-1][0]=1;
			town[root[0]-1][1]=i+1;
		}else if(i==k){
			printf("%d",root[i-1]);
			return 0;
		}else{
			root[i]=a[root[i-1]-1];
			if(town[root[i]-1][0]==0){
				town[root[i]-1][0]=1;
				town[root[i]-1][1]=i+1;
			}else{
				//printf("break \n");
				break;
			}
		}
		//printf("%d %d\n",i+1,root[i]);
	}
	
	int temp;
	temp=((k-town[root[i]-1][1]))%(i-town[root[i]-1][1]+1)+town[root[i]-1][1];
	//printf("%d %d",town[root[i]-1][1],i-town[root[i]-1][1]+1);
	printf("%d",root[temp-1]);
	return 0;
}

/*for(i=0;;i++){
		if(i==0){
			count[0]=1;
		}
		count[i+1]=a[count[i]-1];
		printf("%d %d %d\n",count[i]-1,a[count[i]-1],count[i+1]);
		if(i==k){
			printf("%d",count[i+1]);
			return 0;
		}
	}
	
	count[0]=count[i+1];*/
