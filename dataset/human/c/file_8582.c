#include<stdio.h>
    #include<math.h> 
    #include<string.h>
    int main(){
    	int n,a[100007];
    	scanf("%d",&n);
    	for(int j = 1;j<=n;j++){
    		scanf("%d",&a[j]);
    	}
    	int i = 1,sum = 0;
    	while(i!=2){
    		i = a[i];
    		sum++;
    		if(sum>100000) break;
    	}
    	if(i==2) printf("%d\n",sum);
    	else printf("-1\n");
    }
