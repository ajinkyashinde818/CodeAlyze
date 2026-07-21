#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void){
    int n,get[100000],i,j,t=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&get[i]);
    }
    
    for(i=1;i<=100;i++){
        int count=0;
        for(j=1;j<=n;j++){
            
            if(i<=get[j]){
                
                count++;
                
            }
            
            
            
        }
        if(i<=count){
           t++;
           
        }
        
    }   
    printf("%d\n",t);
    
    
}
