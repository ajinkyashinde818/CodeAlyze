#include <stdio.h>
#define N 100000
#define node0 -1
int depth(int);
int degree(int);
typedef struct{
  int p,r,l;
}Node;
Node T[N];


int main(){
  int i,n,k,id,j,c,keep;  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=node0;
    T[i].r=node0;
    T[i].l=node0;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      T[c].p=id;
      if(j==0){
	T[id].l=c;
      }
      else{
	T[keep].r=c;
      }
      keep=c;   
    }
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,depth(i));
    if(T[i].p==node0){
      printf("root, [");
    }
    else if(T[i].l==node0){
      printf("leaf, [");
    }
    else{
      printf("internal node, [");
    }
    degree(T[i].l);
    printf("]\n");
  }
  return 0;
}
int depth(int nodeNum){
  int count=0;
  if(T[nodeNum].p==node0){
    return 0;
  }
  else{
    count=depth(T[nodeNum].p)+1;
    return count;
  }
}
int degree(int treeNum){
  if(treeNum==node0){
    return 0;
  }
  else{
    if(T[treeNum].r==node0){
      printf("%d",treeNum);
    }
    else{
      printf("%d, ",treeNum);
      degree(T[treeNum].r);
    }
  }
}
