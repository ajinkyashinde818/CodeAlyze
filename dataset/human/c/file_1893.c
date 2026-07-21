#include<stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int b[n];
  int c[n];
  int x=0; //mannzokudo
  for(int i=0;i<n;i++){scanf("%d",&a[i]);}
  for(int i=0;i<n;i++){scanf("%d",&b[i]);}
   for(int i=0;i<n;i++){scanf("%d",&c[i]);}
  for (int i=0;i<n;i++){
    int y=a[i]-1;
    x=x+b[y];// printf("%d",x);
    if(a[i+1]-a[i]==1){
      x=x+c[y];
    }
    }
printf("%d\n",x);
}
