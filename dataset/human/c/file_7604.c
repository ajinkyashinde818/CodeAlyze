#include<stdio.h>
int main(){
    int i=0, y;
    
    int array[10000]={0};
    
     while(i<10000){
         scanf("%d",&array[i]);
         if(array[i]==0) break;
         i++;
     } 
     
     for(y=0; y<i; y++){
		printf("Case %d: %d\n",y+1,array[y]);
     }
}
