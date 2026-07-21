#include<stdio.h>

#define MAX 100005
#define NIL -1

struct Node{int p,l,r,ls,rs;};
struct Node T[MAX];
int n,D[MAX],M=0;

int getDepth(int u){
  int d=0;
  while(T[u].p != -1){
    u = T[u].p;
    d++;
  }
  return d;
}


int getSibling(int s){
  int i; 
  for(i=0; i<n; i++){
    if(s == T[i].l)return T[i].ls;
    if(s == T[i].r)return T[i].rs;
  }
  return -1;
}

int height(struct Node p,int h){
  
  int l=0,r=0;
  if(p.r==-1 && p.l==-1){ return 0; }
  if(p.r!=-1)r = height(T[p.r],r);
  if(p.l!=-1)l = height(T[p.l],l); 
  
  if(l<r) M = r+1;
  
  else M =l+1;
  
  return M;
  
  
}


int getDegree(int d){
  if(T[d].l != -1  && T[d].r != -1) return 2;
  else if(T[d].l == -1 && T[d].r != -1)return 1;
  else if(T[d].l != -1 && T[d].r == -1)return 1;
  else return 0;
}

void print(int u){
  int i=0,count=0;
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",u,  T[u].p,  getSibling(u), getDegree(u));
  printf("depth = %d, height = %d, ", D[u], height(T[u], 0));
  if(D[u] == 0)printf("root\n");
  else if(T[u].l != -1 || T[u].r != -1)printf("internal node\n");
  else printf("leaf\n");
  M = 0;
}



main(){
  int i,j,d,v,c,l;
  
  scanf("%d",&n);

  for (i=0; i<n; i++){
    T[i].p = T[i].l = T[i].r = T[i].ls = T[i].rs = NIL;
  }
  
  for (i=0; i<n; i++){
    scanf("%d",&v);
    for (j=0; j<2; j++){
      scanf("%d",&c);
      

      if(j == 0){
	T[v].l = c;
	T[c].p = v;
	T[v].rs = c; 
      }
      else if(j == 1){
	T[v].r = c;
	T[c].p = v;
	T[v].ls = c;
      }
    }
  }
  for (i=0; i<n; i++){
    D[i] = getDepth(i);
  }



   for (i=0; i<n; i++) print(i);
  return 0;
}
