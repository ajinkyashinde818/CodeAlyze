#include<stdio.h>
typedef struct Node{
  int parent,left,right;
}Node;  
Node T[100000];
int n,D[100000];
void print(int p){
  int i,s;
  printf("node %d: parent = %d, depth = %d, ", p, T[p].parent, D[p]);
  if(T[p].parent==-1)
    printf("root, [");
  else if(T[p].left==-1)
    printf("leaf, [");
 else
    printf("internal node, [");
  s = T[p].left;
  for(i = 0; s!=-1;i++,s = T[s].right){
    if(i)
      printf(", "); 
    printf("%d", s);
  } 
  printf("]\n");
} 
int depth(int x, int y){
  D[x]=y;
    
  if(T[x].right!=-1){
    depth(T[x].right, y);
  }
  if(T[x].left!=-1){
    depth(T[x].left, y+1);
  }
}
int main(){
  int a,b,c,left,right,i,j;
  scanf("%d", &n);
  for(i=0; i<n; i++)
    T[i].parent=T[i].left=T[i].right=-1;   
  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);    
    for(j=0;j<b;j++){
      scanf("%d",&c); 
      if(j==0)
    T[a].left=c;    
      else
    T[left].right=c;  
      left = c;
      T[c].parent=a;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==-1)
      right=i;
  }
  depth(right, 0);
  for(i=0;i<n;i++)
    print(i);
  return 0;
}
