#include<stdio.h>
#include<stdlib.h>
#define df 0
#define MAX 100000

int q[2][MAX];
int head[2]={},tail[2]={};
void enq(int a,int t);
int deq(int t);
void enq(int a,int t){
  q[t][tail[t]++]=a;
}
int deq(int t){
  return q[t][head[t]++];
}
int comp(const void *a,const void *b){
  int x=*((int*)a), y=*((int*)b);
  return (x-y)*x;
}

int main(){
  int n;
  scanf("%d",&n);
  int i;  
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if(a>0) enq(a,0);
    else enq(a,1);
  }
  qsort(q[0],tail[0],sizeof(int),comp);
  qsort(q[1],tail[1],sizeof(int),comp);
  if(tail[0]==0){
    enq(deq(1),0);
  }
  if(tail[1]==0){
    enq(deq(0),1);
  }
  if(df){
    int t;
    for(t=0;t<2;t++){
    printf("q[%d]:[",t);
      for(i=head[t];i<tail[t];i++)printf(" %d",q[t][i]);
      printf(" ]\n");
    }
  }
  int s=0;
  for(i=head[0];i<tail[0];i++){
    s+=q[0][i];
  }
  for(i=head[1];i<tail[1];i++){
    s-=q[1][i];
  }
  printf("%d\n",s);
  while(tail[0]-head[0]>1){
    int a=deq(0),b=deq(1);
    printf("%d %d\n",b,a);
    enq(b-a,1);
  if(df){
    int t;
    for(t=0;t<2;t++){
    printf("q[%d]:[",t);
      for(i=head[t];i<tail[t];i++)printf(" %d",q[t][i]);
      printf(" ]\n");
    }
  }
  }
  while(tail[1]-head[1]>1){
    int a=deq(0),b=deq(1);
    printf("%d %d\n",a,b);
    enq(a-b,0);
    if(df){
      int t;
      for(t=0;t<2;t++){
	printf("q[%d]:[",t);
	for(i=head[t];i<tail[t];i++)printf(" %d",q[t][i]);
	printf(" ]\n");
      }
    }
  }
  printf("%d %d\n",q[0][head[0]],q[1][head[1]]);
}
