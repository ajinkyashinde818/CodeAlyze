#include<stdio.h>
#include<stdlib.h>

 typedef struct tree{
  int p,l,r;
}t;

 t T[25];
 
int Height(int);
int n;

int main(){
  int i,j,id,left,right;
  int s[25],deg[25],dep[25],h[25];
 
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r= s[i]=-1;
    deg[i]=dep[i]= h[i]=0;
  }
 
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
 
    if(right!=-1){
      T[right].p=id;
      deg[id]++;
    }
    if(left!=-1){
      T[left].p=id;
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
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,s[i],deg[i],dep[i],h[i]);
 
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
 
int Height(int a){
  int j,c=0,max=0;
 
  for(j=0;j<n;j++){
    if(T[j].p==a){
      c=Height(j)+1;
 
      if(c>max){
    max=c;
      }
    }
  }
 
  return max;
}
