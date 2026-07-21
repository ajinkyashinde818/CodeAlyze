#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int p;
  int s;
  int c;
  int r;
  int l;
} Tree;
 
int n;
Tree *T;
 
int getdepth(int u){
 
  int a = 0;
 
  while(T[u].p >= 0){
    u = T[u].p;
    a++;
  }
  return a;
}

int getheight(int x, int y){

  int a=0, b=0;
   
  if(T[x].r != -1){
    a = getheight(T[x].r, y+1);
  }  
  if(T[x].l != -1){
    b = getheight(T[x].l, y+1);
  } 
  if(T[x].l == -1 && T[x].r == -1){
    return y;
  }
  if(a>=b){
    return a;
  }
  else return b;
}
 
void print(void){
 
  int i;
 
  for(i=0;i<n;i++){
 
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",T[i].id,T[i].p,T[i].s,T[i].c,getdepth(i),getheight(i,0));

    if(T[i].c == 0 && T[i].p != -1)
      printf("leaf");
    else if(T[i].c != 0 && T[i].p != -1)
      printf("internal node");
    else
      printf("root");
    printf("\n");
  }
}
 
 
int main(){
 
  int i,node,c,l,r;

  scanf("%d",&n);
 
  T = malloc(n * sizeof(Tree));
 
  for(i=0;i<n;i++){
    T[i].id = T[i].p = T[i].s = T[i].l = T[i].r = -1;
    T[i].c = 0;
  }
 
  for(i=0;i<n;i++){
    c = 0;
    scanf("%d",&node);
    scanf("%d %d",&T[node].l,&T[node].r);
    T[node].id = node;
    if(T[node].l != -1){
      T[T[node].l].p = node;
      T[T[node].l].s = T[node].r;
    }

    if(T[node].r != -1){
      T[T[node].r].p = node;
      T[T[node].r].s = T[node].l;
    }



    if(T[node].l == -1) c++;
    if(T[node].r == -1) c++;

    if(c == 0) T[node].c = 2;
    else if(c == 1) T[node].c = 1;
    else T[node].c = 0;

  }
  print();
  free(T);
  return 0;
}
