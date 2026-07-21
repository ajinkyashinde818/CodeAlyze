#include<stdio.h>
int main(void)
{
 int a,b,c;
 scanf("%d %d",&a,&b);
 if(a==0){
  if(b>=1868&&b<=1911){
   c=b-1867;
   printf("M%d\n",c);
  }
  else if(b>=1912&&b<=1925){
   c=b-1911;
   printf("T%d\n",c);
  }
  else if(b>=1926&&b<=1988){
   c=b-1925;
   printf("S%d\n",c);
  }
  else{
   c=b-1988;
   printf("H%d\n",c);
  }
 }
 else if(a==1){
  c=b+1867;
 }
 else if(a==2){
  c=b+1911;
 }
 else if(a==3){
  c=b+1925;
 }
 else{
  c=b+1988;
 }
 if(a!=0){
  printf("%d\n",c);
 }
 return(0);
}
