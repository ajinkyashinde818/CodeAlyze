#include<stdio.h>

typedef struct {
  int node;
  int p,l,r,s;
  int d,h;
  int depth;
  int type;
} Node;

Node T[25];

int depth(int count,int p){
  count++;
  if(T[p].p == -1) return count;
  depth(count,T[p].p);
}

int height(int i){
  int h = 0,t = 0;
    if(T[i].l == -1 && T[i].r == -1) return 0;

    if(T[i].l != -1) h = height(T[i].l) + 1;
    if(T[i].r != -1) t = height(T[i].r) + 1;

    if(h > t) return h;
    else return t;
}

int main(){
  int n,i,m,l,r;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    T[i].p = T[i].l = T[i].r = T[i].s = -1;
    T[i].d = 0;
    T[i].type = 2;

  }

  for(i = 0;i < n;i++){
    scanf("%d%d%d",&m,&l,&r);
    T[m].node = m;
    T[m].l = l;
    T[m].r = r;
    if(l > -1){
      T[m].d++;
      T[l].p = m;
    }
    if(r > -1){
      T[m].d++;
      T[r].p = m;
    }
    if(l > -1 && r > -1){
      T[l].s = r;
      T[r].s = l;
    }
  }

  for(i = 0;i < n;i++){
    if(T[i].p == -1) T[i].type = 0;
    else if(T[i].l != -1 || T[i].r != -1) T[i].type = 1;
    T[i].depth = depth(-1,T[i].node);
  }

  for(i = 0;i < n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", T[i].node,T[i].p,T[i].s,T[i].d,T[i].depth,height(i));
    if(T[i].type == 0) printf("root\n");
    else if(T[i].type == 1) printf("internal node\n");
    else printf("leaf\n");
  }

  return 0;
}
