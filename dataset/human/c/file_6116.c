#include<stdio.h>
#include<stdlib.h>
#define nMIN 2
#define nMAX 200000
#define RtMIN 1
#define RtMAX 1000000000


int main(){
int R[nMAX],Time,i,max=0,sub;

scanf("%d",&Time);
if(nMIN<=Time&&Time<=nMAX){
for(i=0;i<Time;i++){
scanf("%d",&R[i]);
if(RtMIN>R[i]||R[i]>RtMAX)exit(1);
}
max=R[i-1];
sub=R[i-1]-R[i-2];
for(i=Time-2;i>=0;i--){

if(max<R[i]&&i!=0){
max=R[i];
}
if(sub<max-R[i]&&R[i]!=max){
sub=max-R[i];
}
}
}
 else exit(1);

printf("%d\n",sub);
return 0;
}
