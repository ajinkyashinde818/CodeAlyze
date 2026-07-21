#include <stdio.h>

 main(){

   int i,N,K;   //ここにheight[N]を一緒に作ったがNが定義されていないのでダメ
   scanf("%d%d",&N,&K);
  int height[N];
   
   for(i=0;i<N;i++){
     scanf("%d",&height[i]);
   }  //ここでheight[]を作る
   
    int j,counter=0; 
   for(j=0;j<N;j++){
     if(height[j]>=K){
       counter++;
     }
   }
   printf("%d",counter);  
   
}
