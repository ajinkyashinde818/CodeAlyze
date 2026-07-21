#include<stdio.h>
int main(){
  int n,i,max,r[200000],result,j,flag=0,max_num,min_num;
  scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf("%d",&r[i]);
    if(i==0){min_num=r[i];continue;}
    if(flag==0 && i==1){
      max=r[i]-r[i-1];
      if(min_num>r[i])min_num=r[i];
      flag=1;continue;}
     if(r[i]-min_num>max)max=r[i]-min_num;
    if(min_num>r[i])min_num=r[i];
   
  }
   printf("%d\n",max); 
  return 0;
}
