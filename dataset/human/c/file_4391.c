#include <stdio.h>
#include <string.h>
int main(void){
    // Your code here!
    int n;
    int d[101][101];
    int i,j;
    scanf("%d",&n);
    int count=0;
    
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            scanf("%d",&d[i][j]);
        }
    }
    
    
    for(i=0;i<n;i++){
            if(d[i][0]==d[i][1]) count++;
            if(d[i][0]!=d[i][1]) count=0;
            
            if(count==3) break;       
                        
            
            
            
            
            
            
    }  
    if(count==3) printf("Yes");
    else printf("No");
    
    return 0;
}
