#include<stdio.h>
#define MAX 100000
#define NO -1

int pa[MAX];
int le[MAX];
int ri[MAX];

int n,Dp[MAX],Hi[MAX];

void depth(int,int);
int height(int);
int sibling(int);
void ans(int);

int main(){

  int v, l, r;
  int root = 0;
  int i;
  int esc;

  scanf("%d",&n);

  for(i = 0; i < n; i++) pa[i] = NO;

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&v,&l,&r);
    le[v] = l;
    ri[v] = r;
    if(l != NO) pa[l] = v;
    if(r != NO) pa[r] = v;
  }

  for(i = 0; i < n; i++){
    if(pa[i] == NO) root = i;
  }

  depth(root,0);
  esc = height(root);

  for(i = 0; i < n; i++) ans(i);

  return 0;
}

void depth(int a,int d){
  if(a == NO) return;
  Dp[a] = d;
  depth(le[a],d+1);
  depth(ri[a],d+1);
}

int height(int a){
  int hi1 = 0,hi2 = 0;
  if(le[a] != NO) hi1 = height(le[a]) + 1;
  if(ri[a] != NO) hi2 = height(ri[a]) + 1;
  return Hi[a] = (hi1 > hi2 ? hi1 : hi2);
}

int sibling(int a){
  if(pa[a] == NO) return NO;
  if(le[pa[a]] != a && le[pa[a]] != NO) return le[pa[a]];
  if(ri[pa[a]] != a && ri[pa[a]] != NO) return ri[pa[a]];
  return NO;
}

void ans(int a){
  int degree = 0;
  printf("node %d: ",a);
  printf("parent = %d, ",pa[a]);
  printf("sibling = %d, ",sibling(a));
  if(le[a] != NO) degree++;
  if(ri[a] != NO) degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",Dp[a]);
  printf("height = %d, ",Hi[a]);

  if(pa[a] == NO) printf("root\n");
  else if(le[a] == NO && ri[a] == NO) printf("leaf\n");
  else printf("internal node\n");
}
