#include<stdio.h>
#define MAX 100000
#define N -1
 
int D[MAX],H[MAX];
int n;
int A;

void print(int);
 
struct Node{ int p, l, r;};
struct Node T[MAX];

void arr(int a){
  if(getD(a) == 0){
    printf("root\n");
  }else if(T[a].r ==N && T[a].l ==N){ 
    printf("leaf\n");
  }else if(T[a].r!=N || T[a].l!= N){
    printf("internal node\n"); 
  }
}
 
 
int getD(int u){
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
 
int par(int a){
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
int hei(int c){
  int l=0;
  int r=0;
 
  if(T[c].l==-1 && T[c].r == -1){
    return 0;
  }
  if(T[c].l!=-1 && T[c].r != -1){
    l = hei(T[c].l)+1;
    r = hei(T[c].r)+1;
    if(l<r){
      return r;
    }
    else return l;
  }
  else if(T[c].l==-1&&T[c].r!=-1){
    return hei(T[c].r)+1;
  }
  else if(T[c].l!=-1&&T[c].r==-1){
    return hei(T[c].l)+1;
  }
}
void print(int u){
  
   
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,par(u),sibling(u),degree(u),D[u],hei(u));
  arr(u);
}
 
 
main(){
  int i, j, d, v, c, l;
  int t;
  int f=0;
 
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = N;
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
      f++;
      if(A == 0){
	break;
      }
      else {
	i = n-1;
      }
    } 
  }

  if(f == 0){
    A= 0;
  }
  
  for(i=0;i<n;i++){
    D[i] = getD(i);
  }
 
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
