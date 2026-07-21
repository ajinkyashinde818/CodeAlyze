#include<stdio.h>

typedef struct{
  int p;
  int s;
  int deg;
  int dep;
  int h;
}data;

typedef struct{
  int id;
  int left;
  int right;;
}node;

int dep;

int getdep(data* T, int i){
  if(T[i].p == -1) return dep;
  dep++;
  return getdep(T, T[i].p);
}

int geth(data* T, node u, int i){
  int hleft=0,hright=0;
  if(u.left!=-1){
    if(T[u.left].h == -1) return -1;
    hleft = T[u.left].h;
  }
  if(u.right!=-1){
    if(T[u.right].h == -1) return -1;
    hright = T[u.right].h;
  }

  if(hleft > hright) return hleft+1;
  else return hright+1;
}

void print(data T, int i){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T.p,T.s,T.deg,T.dep,T.h);
  if(T.p == -1) printf("root");
  else if(T.deg == 0) printf("leaf");
  else printf("internal node");
  printf("\n");
}
int main(){
  int n,i,j;
  data T[25];
  node u[25];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].deg = 0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&u[i].id,&u[i].left,&u[i].right);
    
    if(u[i].right != -1){
      T[u[i].right].p = u[i].id;
      T[u[i].id].deg++;
    }
    if(u[i].left != -1){
      T[u[i].left].p = u[i].id;
      T[u[i].id].deg++;
    }

    if(T[u[i].id].deg == 0) T[u[i].id].h = 0;
    else T[u[i].id].h =-1;
  }

  for(i=0;i<n;i++){
    T[i].s = -1;
    for(j=0;j<n;j++){
      if(i != j && T[i].p == T[j].p){
        T[i].s =j;
        T[j].s =i;
      }
    }
  }

  for(i=0;i<n;i++){
    dep=0;
    T[i].dep = getdep(T,i);
  }

  i=0;
  while(1){
    if(T[i].p == -1 && T[i].h != -1) break;
    if(T[i].h != 0){
      j=0;
      while(u[j].id != i) j++;
      T[i].h = geth(T,u[j],i);
    }

    if(i == n-1) i=0;
    else i++;
  }
  for(i=0;i<n;i++) print(T[i],i);

  return 0;
}
