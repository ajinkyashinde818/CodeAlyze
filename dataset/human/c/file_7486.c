#include <stdio.h>
int main(void)
{
    int i ,a[10000], c;
    
    
    for(i=0;i<10000;i++){
    	scanf("%d",&a[i]);
    	if(a[i]==0){
    		break;
    	}
    }
    c = i;
    
    for(i=0;i<c;i++){
    	printf("Case %d: %d\n",i+1 ,a[i]);
    }
    return 0;
}
