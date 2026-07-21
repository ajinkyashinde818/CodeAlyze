#include<stdio.h>
#define MAX 100005
#define NIL -1
 
int D[MAX],H[MAX];
int n;
int A;
/*
 p: parent
 l: left-child
 r: right sibling
 */
void print(int);
 
struct Node{ int p, l, r;};
struct Node T[MAX]; // Tree
 
int getDepth(int u);
void tree(int a);
void hairetu(int);
int parent(int);
int sibling(int);
int degree(int);
int height(int);
 
 
void hairetu(int a){
  int leaf;
   
  if(getDepth(a) == 0){
    printf("root\n");
  }
// leaf
  else if(T[a].r ==NIL && T[a].l ==NIL){
      printf("leaf\n");
    }
  
  // internal node
  else if(T[a].r!=NIL || T[a].l!= NIL){
    printf("internal node\n"); 
  }
}
 
 
int getDepth(int u){
  int d = 0;
  int i;
  if(u == A) return 0;
  else{
    i = n-1;
    while(1){
      if(u == A) break;
      if(T[i].l == u || T[i].r == u){
    d++;
    u = T[i].p;
      }
      i--;
      if(i<0) i = n-1;
    }
    return d;
  }
   
}
 
int parent(int a){
  int i;
  if(a==A) return -1;
  else {
  for(i=0;i<n;i++){
    if(T[i].l==a || T[i].r == a){
      return T[i].p;
      break;
  }
  }
  }
}
 
int sibling(int b){
  int i;
  if(b==A) return -1;
  else {
    for(i=0;i<n;i++){
      if(T[i].l == b){
    return T[i].r;
      }
      if(T[i].r == b){
    return T[i].l;
      }
    }
  }
}
 
int degree(int d){
  if(T[d].l==-1 && T[d].r == -1){
    return 0;
  }
  else if(T[d].l != -1 && T[d].r != -1){
    return 2;
  }
  else if((T[d].l == -1 && T[d].r != -1) || (T[d].l != -1 && T[d].r == -1)){
    return 1;
  }
  
}
int height(int c){
  int l=0;
  int r=0;
 
  if(T[c].l==-1 && T[c].r == -1){
    return 0;
  }
  if(T[c].l!=-1 && T[c].r != -1){
    l = height(T[c].l)+1;
    r = height(T[c].r)+1;
    if(l<r){
      return r;
    }
    else return l;
  }
  else if(T[c].l==-1&&T[c].r!=-1){
      return height(T[c].r)+1;
    }
  else if(T[c].l!=-1&&T[c].r==-1){
      return height(T[c].l)+1;
    }
}
void print(int u){
  
   
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,parent(u),sibling(u),degree(u),D[u],height(u));
  hairetu(u);
}
 
 
main(){
  int i, j, d, v, c, l;
  int t;
  int flag=0;
 
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
 
  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &d, &c);
 
    T[v].p = v;
     
    T[v].l = d;
 
    T[v].r = c;
     
 
  }
  A = 0;
  for(i=n-1;i>0;i--){
    if(T[i].l==A || T[i].r==A){
      A = T[i].p;   
      flag++;
      if(A == 0){
    break;
      }
    else {
      i = n-1;
    }
    } 
  }

  if(flag == 0){
    A= 0;
  }
  
  
  for(i=0;i<n;i++){
    D[i] = getDepth(i);
  }
 
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
