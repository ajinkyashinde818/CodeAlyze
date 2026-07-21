#include <stdio.h>
int main(){
    int n,k,p,i,o;
    
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){

   		scanf("%d%d",&k,&p);
   		o=k%p;
        
        
   		if(o==0){
   		     printf("%d\n",p);
   		}
        
    	if(o!=0){
        	printf("%d\n",o);
    	}
        
    }      
    return 0;
}
