#include<stdio.h>
#include<string.h>
#include<math.h>
 
 
int main(){
   int n,k,s;
   scanf("%d%d%d", &n,&k,&s);
   for(int i=0;i<n;i++){
     if(s<1000000000){
     	if(i<k){
     		printf("%d", s);
        }else {
            printf("%d", s+1);
        }
      } else{
         if(i<k){
     		printf("%d", s);
        }else {
            printf("1");
        }	 
      }
      if(i!=n-1){
         	printf(" "); 
      }
   }
	return 0;
}
