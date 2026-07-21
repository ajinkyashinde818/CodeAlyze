#include <stdio.h>
#define nil -1
#define N 100001

typedef struct{
  int parent;
  int R_sibling;
  int L_child;
}BT;

BT bt[N];

int C_depth(int a){
  int deep = 0;
  while(bt[a].parent != nil){
    deep++;
    a = bt[a].parent;
  }
  return deep;
}

void WRU(int b){
  if(bt[b].parent == nil)printf(" root,");
  else if(bt[b].L_child == nil) printf(" leaf,");
  else printf(" internal node,");
}

void C_child(int c){
  int i;
  printf(" [");

  for(i=bt[c].L_child;i != nil;i=bt[i].R_sibling){
    if(bt[i].R_sibling == nil) printf("%d",i);
    else printf("%d, ",i);
  }

  printf("]\n");
}

int main(){
  int n,mem,ins,hol[N],num;
  int i,j;

  scanf("%d",&n);

  //必要数初期化
  for(i=0;i<n;++i){
    bt[i].parent = nil;
    bt[i].R_sibling = nil;
    bt[i].L_child = nil;
  }

  //データ入力

  for(i=0;i<n;++i){
    scanf("%d%d",&num,&mem);

    for(j=0;j<mem;++j){
      scanf("%d",&hol[j]);

      if(j==0){
	bt[num].L_child = hol[j];
	bt[bt[num].L_child].parent = num;
      }
      else {
	bt[hol[j-1]].R_sibling = hol[j];
	bt[hol[j]].parent = num;
      }
    }
  }
  for(i=0;i<n;++i){
    printf("node %d: ",i);
    printf("parent = %d, ",bt[i].parent);
    printf("depth = %d,",C_depth(i));
    WRU(i);
    C_child(i);
  }
  
 
  return 0;
}
