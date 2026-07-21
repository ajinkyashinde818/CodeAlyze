#include<stdio.h>
#include<string.h>

#define MAX 100000
#define LEN 15

struct node{
  int right;
  int left;
  int dep;
  int par;
  char type[LEN];
};

struct node T[MAX];

void deps(int a, int b){
  T[a].dep = b;
  if(T[a].right != -1){
    deps(T[a].right,b);
  }
  if(T[a].left != -1){
    deps(T[a].left,b+1);
  }
}


void printC(int a){
  int c;
  c=T[a].left;
  printf("[");
  while(c!= -1){
    printf("%d", c);
    if(T[c].right != -1){
      printf(", ");
    }
      c= T[c].right;
  }
  printf("]\n");
  
}


int main(){

  int i,j,k,c[MAX],id,root,n;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].par = T[i].left = T[i].right = -1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    if(k==0){
      c[0] = -1;
    }
    
    for(j=0;j<k;j++){
      scanf("%d", &c[j]);
    }
    
    for(j=0;j<k;j++){
      T[c[j]].par = id;
      if(j != k-1){
	T[c[j]].right = c[j+1];
      }
    }  
    T[id].left = c[0];
  }
  
  for(i=0;i<n;i++){
    if(T[i].par == -1) root = i;
  }

  deps(root, 0);
      
  for(i=0;i<n;i++){
    if(T[i].par == -1){
      strcpy(T[i].type, "root");
    }
    else if(T[i].left == -1){
      strcpy(T[i].type, "leaf");
    }
    else{
      strcpy(T[i].type, "internal node");
    }
    printf("node %d: parent = %d, depth = %d, %s, ", i, T[i].par, T[i].dep, T[i].type);
    printC(i);
  }
  return 0;
}
