#include <stdio.h>

#define N 100000
#define NIL -1
typedef struct{
  int par;
  int left;
  int right;
}node_tree;


node_tree C[N];
int n;
int D[N];

//深さ
int Deep(int a){
  int d;
  for(d=0;C[a].par!=NIL;d++){
    a=C[a].par;
  }
  return d;
}



//結果出力と判定
void Printing(int a){
  int i;
  printf("node %d: parent = %d, depth = %d, ",a,C[a].par,D[a]);
  if(C[a].par==NIL){
    printf("root, ");
  }
  else if(C[a].left!=NIL){
    printf("internal node, ");
  }
  else if(C[a].left==NIL){
    printf("leaf, ");
  }
   printf("[");
  if(C[a].left!=NIL){
    printf("%d",C[a].left);
    a=C[a].left;
    if(C[a].right!=NIL) printf(", ");
     
    while(C[a].right!=NIL){
      printf("%d",C[a].right);
      a=C[a].right;
      if(C[a].right!=NIL) printf(", ");
    }
  }
  printf("]\n");
}
 





main(){
  int i,j,deg,ver,ch,l;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    C[i].par=NIL;
    C[i].left=NIL;
    C[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&ver,&deg);
    for(j=0;j<deg;j++){
      scanf("%d",&ch);
      C[ch].par=ver;
      if(j==0) C[ver].left=ch;
      if(j>0) C[l].right=ch;
      l=ch;
    }
  }
  //深さをループで回していく
  for(i=0;i<n;i++){
    D[i]=Deep(i);
  }
  //それぞれの出力にはループを回しながら
  for(i=0;i<n;i++){
    Printing(i);
  }
  return 0;
}
