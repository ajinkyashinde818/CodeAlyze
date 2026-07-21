#include <stdio.h>

main() {
    
        int n;
  
        scanf("%d\n", &n);
        
        for(int i=1;i<=n;i++){
            int k,p;
            scanf("%d %d\n",&k,&p);
            
            if(k>=p){
                if(k%p==0){
                    printf("%d\n",p);
                }else{
                    printf("%d\n",k%p);
                }
            }else{
                printf("%d\n",k);
            }
        }

  return 0;
}
