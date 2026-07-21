#include<stdio.h>
#define P_EDGE 200000
 
int makelist(int* list,int kazu){
    int i,j;
    for(i=0;i<kazu;i++){
        list[i]=1;
    }
    list[0]=0;
    list[1]=0;
    for(i=2;i<kazu;i++){
        if(list[i]){
            for(j=2*i;j<kazu;j+=i){
                list[j]=0;
            }
        }
    }
    return 0;
}

int main(){
	int plist[P_EDGE];
	int n,c;
	long long int ans;
	int i;
	makelist(plist,P_EDGE);
	while(1){
		c=0;
		ans=0;
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<P_EDGE;i++){
			if(plist[i]!=0){
				c++;
				ans+=i;
				if(c==n){
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
