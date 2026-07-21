#include<stdio.h>

//dp seearch 
//res = max(res,Rj - minRi)
//scan one time
int main(){
   int min_i = 0;//first input
   int j = 0; // second input
   int ans = -1000000500;
   int n = 0;
   scanf("%d",&n); 
   scanf("%d",&min_i); 
   for(int k = 1; k<n; k++){
     scanf("%d",&j);
     if(j-min_i>ans) ans = j-min_i;
     if(min_i>j) min_i = j; 
   }
printf("%d\n",ans);
   return 0;
}
