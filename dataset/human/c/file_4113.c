#include <stdio.h>

int main(void) {
    
    
    
    int tmp,x,y,i=0,k,count=0,ans=0,arr[3];
    for(i=0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    x = arr[0];
    y = arr[1];
    k = arr[2];
    while (x % y != 0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    
        for(i=y; i >0; i--)
        {
            if (y%i == 0)
            {
                ans = i;
                count++;
                if(count==k){
                    printf("%d",ans);
                    break;
                }
            }
        }
    
    
    
    return 0;
}
