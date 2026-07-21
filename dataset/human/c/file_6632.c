#include <stdio.h>

int main(void)
{
    int a;
    int i = 0;
    int j;
    int max = -1000000000;
    int current =-1000000000;
    
    scanf("%d",&a);
    
    int b[a];
    
    for(j = 0; j < a; j++){
        scanf("%d\n",&b[j]);
    }
    
    for(j = 0; j < a; j++){
        if(current > b[a-j-1] && i != 0){
            continue;
        }
            
        for(i = j; i < a-1; i++){
            
            if(b[a-1-j] - b[i-j] > max){
                max = b[a-1-j] - b[i-j];
                current = b[a-1-j];
                //printf("%d %d\n",b[a-1-j], max);
            }
        }
    }
    printf("%d\n",max);
    
	return 0;
}
