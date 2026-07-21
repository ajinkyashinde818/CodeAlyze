#include <stdio.h>

int main() {

    int i,s;
    i = s = 0;
    int x[10000];

    while(1){
    	scanf("%d", &x[i]);
    	i++;
    	if(x[i-1]==0){
    		break;
    	}
    }

    for(s=0;s<i-1;s++){
    	printf("Case %d: %d\n",s+1, x[s]);
    }

    return 0;
}
