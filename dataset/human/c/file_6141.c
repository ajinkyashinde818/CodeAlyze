#include<stdio.h>
int max_pro(int [],int);
int main(){
  int number;
  int list[200000];
  int i;
  scanf("%d",&number);
  for(i=0;i<number;i++){
    scanf("%d",&list[i]);
  }
  printf("%d\n",max_pro(list,number));
  return 0;
}
int max_pro(int l[],int n){
int i;
int min=l[0];
int max=l[1];
int dif=max-min;
for(i=1;i<n;i++){
  if(min>l[i]){
    min=l[i];
    max=l[i];
  }
  else if(max<=l[i]){
    max=l[i];
    if(dif<max-min)dif=max-min;
}
}
  return dif;
}
