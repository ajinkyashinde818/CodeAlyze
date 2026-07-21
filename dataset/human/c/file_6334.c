#include<stdio.h>
int main(){
  int i, num,alt,max=0,min=0;
  scanf("%d",&num);
  int buf[num];
  for(i=0;i<num;i++){
    scanf("%d",&buf[i]);
  }
  max=buf[1]-buf[0];
  min=buf[0]; 
  for(i=1;i<num;i++){
    if(max<buf[i]-min)max=buf[i]-min;
    if(min>buf[i])min=buf[i];
  
  }
  printf("%d\n",max);
  return 0;
}
