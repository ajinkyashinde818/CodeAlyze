#include <stdio.h>
int casep(int i);

int main(void) {
    int i = 1;
    
    while(1){
    	if(casep(i) == 0)break;
    	i++;
    }
return 0;
}

int casep(int i){
	int x ;
	
	scanf("%d",&x);
	if (x == 0) return 0;
	else{
		printf("Case %d: %d\n",i,x);
		return 1;
		}
	
}
