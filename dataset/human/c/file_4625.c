#include<stdio.h>
#include<stdlib.h>
 
#define MAX 26
 
typedef struct node{
  int p;
  int l;
  int r;
} Tree;
 
int Height(int);
 
int n;
Tree T[MAX];
 
int main(){
  int i,j,id,left,right;
  int s[MAX],deg[MAX],dep[MAX],h[MAX];
 
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].p=-1;
    T[i].l=-1;
    T[i].r=-1;
    s[i]=-1;
    deg[i]=0;
    dep[i]=0;
    h[i]=0;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
 
    if(left!=-1){
      T[left].p=id;
      deg[id]++;
    }
 
    if(right!=-1){
      T[right].p=id;
      deg[id]++;
    }
 
    T[id].l=left;
    T[id].r=right;
    s[left]=right;
    s[right]=left;
  }
 
  for(i=0;i<n;i++){
    j=i;
     
    while(T[j].p!=-1){
      j=T[j].p;
      dep[i]++;
    }  
 
    h[i]=Height(i);
  }
 
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
       ,i,T[i].p,s[i],deg[i],dep[i],h[i]);
 
    if(T[i].p==-1){
      printf("root\n");
    }else if(T[i].l==-1 && T[i].r==-1){
      printf("leaf\n");
    }else{
      printf("internal node\n");
    }
  }
 
  return 0;
}
 
int Height(int i){
  int j,count=0,max=0;
 
  for(j=0;j<n;j++){
    if(T[j].p==i){
      count=Height(j)+1;
 
      if(count>max){
    max=count;
      }
    }
  }
 
  return max;
}
