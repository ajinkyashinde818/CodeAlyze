#include<stdio.h>
#define MAX 100000

typedef struct{
  int p,l,r;
}Node;
Node N [MAX];

int Depth(int i){//id　の深さ　上中
  int count=0;
  Node X=N[i];
  
  for(;X.p!=-1;count++)X=N[X.p];
  return count;
}

int Degree(int i){//子供の数　0-2
  int count=0;
  if(N[i].r!=-1)count++;
  if(N[i].l!=-1)count++;

  return count;
}

int Sibling(int i){//兄弟の id を返す
  int R,L;

  if(N[i].p==-1)return -1;
  L=N[N[i].p].l;
  R=N[N[i].p].r;

  return i!=L?L:R;
}

int Height(int i){//idの中下
  Node X=N[i];
  int a,b;
  a=b=0;
  
  if(X.r!=-1)a=Height(X.r)+1;//左右の子供をたどって長い方を高さとして採用
  if(X.l!=-1)b=Height(X.l)+1;
    
  return  a>=b ? a : b;
}



void Print(int i){
  int j;
  
  printf("node %d: ",i);
  printf("parent = %d, ",N[i].p);

  printf("sibling = %d, ",Sibling(i));
  printf("degree = %d, ",Degree(i));
  
  printf("depth = %d, ",Depth(i));
  printf("height = %d, ",Height(i));

  if(N[i].p==-1)printf("root\n");//親がいなかったらルート
  else if(N[i].l==-1&&N[i].r==-1)printf("leaf\n");//子供いなかったら葉
  else printf("internal node\n");//ほかはinternal
  return ;
}

int main(){
  int n;
  int i;
  int j;
  
  scanf("%d",&n);

  for(i=0;i<100000;i++){//INITIATE
    N[i].p = N[i].l = N[i].r = -1;
  }

  for(i=0;i<n;i++){//input
    scanf("%d",&j);
    scanf("%d",&N[j].l);
    scanf("%d",&N[j].r);
      
    if(N[j].l!=-1) N[N[j].l].p = j;//子供がいたら、そいつらの親おや決定
    if(N[j].r!=-1) N[N[j].r].p = j; 
  }
  
  
  for(i=0;i<n;i++){//idごとに必要
    Print(i);	
  }
  return 0;
}
