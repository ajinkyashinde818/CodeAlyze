#include <stdio.h>
#include <limits.h>
 
int main(){
    int n,a,min=INT_MAX,max=INT_MIN;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(max<a-min){
	  max=a-min;
	}
	if(min>a){
	  min=a;
	}
    }
    printf("%d\n",max);
    return 0;
}
