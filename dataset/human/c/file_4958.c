#include<stdio.h>

#define N 25

typedef struct{
  int parent;
  int left;
  int right;
}Node;

int childhigh(int);
Node T[N];

int main(){
  int id,n,i,j=0,k,c,sibling,deg,high;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=T[i].right=T[i].left=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&T[id].left,&T[id].right);
    if(T[id].left!=-1)T[T[id].left].parent=id;
    if(T[id].right!=-1)   T[T[id].right].parent=id;
  }
  for(k=0;k<n;k++){
    j=k;
    c=0;
    while(T[j].parent!=-1){
      c++;
      j=T[j].parent;
    }
    printf("node %d: parent = %d, ",k,T[k].parent);
    if(T[k].parent!=-1){
    if(k==T[T[k].parent].right)sibling=T[T[k].parent].left;
    else sibling=T[T[k].parent].right;
    printf("sibling = %d, ",sibling);
    } else {
      sibling=-1;
      printf("sibling = %d, ",sibling);
    }
    if(T[k].left!=-1 && T[k].right!=-1)deg=2;
    else if((T[k].left!=-1 && T[k].right==-1) || (T[k].left==-1 && T[k].right!=-1)) deg=1;
    else if(T[k].left==-1 && T[k].right==-1)deg=0;
    printf("degree = %d, depth = %d, ",deg,c);

    high=childhigh(k);
    printf("height = %d, ",high);
   





    if(T[k].parent==-1)printf("root\n");
    else if(T[k].right==-1 && T[k].left==-1)printf("leaf\n");
    else printf("internal node\n");
    }
  return 0;
}

int childhigh(int k){
  int count=0,a,b;
  if(T[k].right==-1 && T[k].left==-1)return 0;
  else if(T[k].right==-1 && T[k].left!=-1){
    count=childhigh(T[k].left);
    return count+1;
  }
  else if(T[k].right!=-1 && T[k].left==-1){
    count=childhigh(T[k].right);
    return count+1;
  }
  else {
    a=childhigh(T[k].left);
    b=childhigh(T[k].right);
    if(a>b)return a+1;
    else return b+1;
  }
}
