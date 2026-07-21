#include<stdio.h>
#define MAX 100001
#define N -1
typedef struct{
  int parent,x,y;
}Node;
Node Tree[MAX];
int u,a,de[MAX];
int get(int);
void pr(int);
int main(){
  int i,j,l,d,v,z;
  scanf("%d" , &u);
  for(i = 0;i < u; i++){
    Tree[i].parent = N;
    Tree[i].x = N;
    Tree[i].y = N;
  }
  for( i = 0; i < u; i++){
    scanf("%d %d", &v,&d);
    for(j = 0;j<d;j++){
      scanf("%d" , &z);
      if(j ==0)Tree[v].x = z;
      else if(j != 0) Tree[l].y = z;
      l = z;
      Tree[z].parent = v;
    }
  }
  
    
  a = 0;
  for(i = 0;i < u; i++){
    de[i] = get(i);
    if(de[i] > a) a = de[i];
  }
  for(i=0;i<u;i++){
    pr(i);
  }
  return 0;
}
int get(int n){
  int d = 0;
  while(1){
    n = Tree[n].parent;
    if(n == N)break;
    d++;
  }
  return d;
}
void pr(int n){
  int i , j;
  printf("node %d: " , n);
  printf("parent = %d, ", Tree[n].parent);
  printf("depth = %d, ", de[n]);
  if(Tree[n].parent == -1)printf("root, ");
  else if(Tree[n].x == -1)printf("leaf, ");
  else{
    printf("internal node, ");
  }
  printf("[");
  for(i=0, j = Tree[n].x;j != N ; i++,j = Tree[j].y){
  
      if(i)printf(", ");
      printf("%d", j);
    }
  
  printf("]\n");
}
