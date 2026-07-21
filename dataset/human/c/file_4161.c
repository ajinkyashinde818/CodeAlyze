#include<stdio.h>
#include<string.h>
int main(void){
  int counter=0;
  int counterb=0;
  int yaku[10000];
  int yakub[10000];
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  for(int i=1;i<=a;i++){
    if(a%i==0){
      yaku[counter]=i;
      counter++;
    }
  } 
   for(int ite=0;ite<counter;ite++){
    if(b%yaku[ite]==0){
      yakub[counterb]=yaku[ite];
      counterb++;
} 
}
  printf("%d",yakub[counterb-c]);
  return 0;
}
