#include <stdio.h>
int main(void){
    int N;
    int a[30];
    int b[30];
    int c[30];
    int sum=0;

scanf("%d",&N);
for(int i=0;i<N;i++){
    scanf("%d",&a[i]);
}

for(int i=0;i<N;i++){
    scanf("%d",&b[i]);
}

for(int i=0;i<N-1;i++){
    scanf("%d",&c[i]);
}
    
for(int i=0;i<N;i++){
   sum=sum+b[i];
if(i!=N-1){
   if(a[i]==a[i+1]-1){
       sum=sum+c[a[i]-1];
   } 
}

}
    printf("%d\n",sum);
    return 0;
}
