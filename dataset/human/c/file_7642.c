#include<stdio.h>
int main(void){
    int a[10000];
    int i;
    for(i=0;i<10000;i++){
        scanf("%d\n",&a[i]);
        if(a[i]==0){
        	break;
        }
    }
    for(i=0;i<10000;i++){
    	if(a[i]==0){
    		break;
    	}
    	printf("Case %d: %d\n",i+1,a[i]);
    }
 
    return 0;
}
