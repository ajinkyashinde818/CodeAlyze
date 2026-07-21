#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define rad M_PI/3
#define N 2147483647
#define Max 500000
#define NTL -1
#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a<b)?b:a)

int main(void)
{
   int h,w,i,j,check=1;
   scanf("%d%d",&h,&w);
   char color[52][52];
   for(i=1;i<h+2;i++){
       for(j=1;j<w+2;j++){
           scanf("%c",&color[i][j]);
       }
   }
   for(i=1;i<h+1;i++){
       for(j=1;j<w+1;j++){
           if(color[i][j]=='#'){
               if(color[i-1][j]=='#'||color[i+1][j]=='#'||color[i][j-1]=='#'||color[i][j+1]=='#'){
                   check=1;
               }else{
                   check=0;
break;
               }
           }
       }
       if(check==0){
           break;
       }
   }
   if(check==1){
       printf("Yes");
   }else{
       printf("No");
   }
   return 0;
}
