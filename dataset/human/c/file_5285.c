#include<stdio.h>
#define NIL -1

typedef struct{
  int parent,left,right;
}tree;

void data_print(tree *,int );
int depth(tree *,int );

int sibling(tree *,int);
int degree(tree *,int);
int height(tree *,int);

int main(){
  tree inf[100001];
  int n,id,pick,num,a,r;
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    inf[i].parent=NIL;
    inf[i].left=NIL;
    inf[i].right=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);

      scanf("%d",&pick);
      if(pick!=NIL){
        inf[id].left=pick;
        inf[pick].parent=id;
    }
      scanf("%d",&pick);
      if(pick!=NIL){
        inf[id].right=pick;
        inf[pick].parent=id;
      }
}

  for(i=0;i<n;i++)data_print(inf,i);

  return 0;
}

void data_print(tree *inf,int i){

  int temp;

  printf("node %d: ",i);

  printf("parent = %d, ",inf[i].parent);

  printf("sibling = %d, ",sibling(inf,i));

  printf("degree = %d, ",degree(inf,i));

  printf("depth = %d, ",depth(inf,i));

  printf("height = %d, ",height(inf,i));

  if(inf[i].parent==NIL)printf("root");

  else if(inf[i].left==NIL && inf[i].right==NIL)printf("leaf");

  else if(inf[i].left!=NIL || inf[i].right!=NIL)printf("internal node");

  printf("\n");
}

int depth(tree *inf,int num){
  int cnt=0,temp;

  while(inf[num].parent!=NIL){
    cnt++;
    temp=inf[num].parent;
    num=temp;
  }
  return cnt;
}

int sibling(tree *inf ,int num){
  int temp;

  if(inf[num].parent==NIL)return -1;
  else temp=inf[num].parent;

  if(inf[temp].left!=NIL && inf[temp].left!=num)return inf[temp].left;
  else if(inf[temp].right!=NIL && inf[temp].right!=num)return inf[temp].right;
else return -1;
}

int degree(tree *inf,int num){
  int c=0;
  if(inf[num].left!=NIL)c++;
  if(inf[num].right!=NIL)c++;
  return c;
}

int height(tree *inf,int num){
  int lef=0,rig=0;

  if(inf[num].left==NIL && inf[num].right==NIL)return 0;

  if(inf[num].left!=NIL)lef=height(inf,inf[num].left)+1;
  if(inf[num].right!=NIL)rig=height(inf,inf[num].right)+1;

  if(lef>rig)return lef;
  else return rig;
}
