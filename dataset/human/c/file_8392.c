#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,k,i;
  scanf("%d",&n);
  char string[n];
  scanf("%s",string);
  scanf("%d",&k);
  for(i=0;i<n;i++){
  if(string[i]!=string[k-1]){
    string[i]='*';
 }
}
 printf("%s\n",string);
 return 0;
}
