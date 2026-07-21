#include <stdio.h>
#define N 100000
 
struct Node{
  int p;
  int left;
  int right;
};
 
struct Node T[N];
int count =0;
int depth(int);
void degree(int);
 
int main(){
  int i,j,n,k,left,right,node,m,c;
   
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p = T[i].left = T[i].right = -1;
  for(i=0;i<n;i++){
    scanf("%d%d",&node,&m);
    for(j=0;j<m;j++){
      scanf("%d",&c);
      T[c].p = node;
      if(j!=0) T[left].right = c;
      else T[node].left = c;
      left = c;
    }
  }
   
  for(i=0;i<n;i++){
    count = 0;
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,depth(i));
    if(T[i].p == -1) printf("root, [");
    else if(T[i].left == -1) printf("leaf, [");
    else  printf("internal node, [");
    count = 0;
    degree(T[i].left);
    printf("]\n");
  }
  return 0;
}
   
int depth(int id){
  if(T[id].p==-1){
 return count;
  }
  else{
    count++;
    return  depth(T[id].p);
  }
}
 
void degree(int id){
  if(id!=-1){
    if(count!=0){
      printf(", ");
    }
    printf("%d",id);
    count++;
    degree(T[id].right);
  }
}
