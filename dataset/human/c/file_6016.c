#include<stdio.h>
    
int main(){
    int i,j,n,Max,key,key2,count=0;
    int A[200001];
        
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
   
   Max=A[2]-A[1];
 key2=A[n];
for(i=n;i>=2;i--){
     
        if(key2<=A[i]){
    for(j=i;j>1;j--){
 
    	
    	if(Max<A[i]-A[j-1]){
           Max=A[i]-A[j-1];
            key=A[j-1];}
          
              
    if(count==1){
    if(key>A[j-1]){
    if(Max<A[i]-A[j-1]){
    Max=A[i]-A[j-1];
    key=A[j-1];}}
 
        key2=A[i];
    }
          count=1; 
              
}
        }}
          
            printf("%d\n",Max);
            return 0;
        }
