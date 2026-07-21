#include<stdio.h>

int main (){
    char a[15];
    int n,k,i,j;
    char z;
    scanf("%d %s %d",&n,&a,&k);
    
    
    z = a[k-1]; // こいつ
    
  for(i = 0;i < n;i++){
    if(a[i] !=  z){
        a[i] = '*';
    }
  }
    
   for(j = 0;j < n;j++){
    printf("%c",a[j]);
   }
        return 0;
  
}
