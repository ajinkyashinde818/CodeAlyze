#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int id;
  int par, lft, rit;
}T_node;
T_node *T;
int cntdeg(T_node *);
int cntdpt(T_node *);
int gethig(T_node *, int);
int main(){
  int n;
  scanf("%d", &n);
  T = (T_node *)malloc(sizeof(T_node) * n);
  int i, id, lcl, rcl;
  for(i = 0; i < n; i++)
    T[i].par = T[i].rit = T[i].lft = -1;
  for(i = 0; i < n; i++){
    scanf("%d", &id);
    T[id].id = id;
    scanf("%d %d", &lcl, &rcl);
    if(lcl >= 0){
      T[id].lft = lcl;
      T[T[id].lft].rit = rcl;
      T[T[id].lft].par = id;
      if(T[T[id].lft].rit >= 0)
	T[T[T[id].lft].rit].par = id;
    }
    else{
      T[id].lft = rcl;
      if(T[id].lft >= 0)
	T[T[id].lft].par = id;
    }
  }
  int sib;
  for(i = 0; i < n; i++){
    sib = -1;
    if(T[i].par < 0){
      if(T[i].lft >= 0)
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, T[i].par, sib, cntdeg(&T[T[i].lft]), cntdpt(&T[i]), gethig(&T[i], 0));
      else
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, T[i].par, sib, 0, cntdpt(&T[i]), gethig(&T[i], 0));
    }
    else{
      if(T[i].rit >= 0)
	sib = T[i].rit;
      else
	sib = T[T[i].par].lft != i ? T[T[i].par].lft : -1;
      if(T[i].lft >= 0)
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", i, T[i].par, sib, cntdeg(&T[T[i].lft]), cntdpt(&T[i]), gethig(&T[i], 0));
      else
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", i, T[i].par, sib, 0, cntdpt(&T[i]), gethig(&T[i], 0));
    }
  }
  free(T);
  return 0;
}

int cntdeg(T_node *t){
  if(t->rit < 0)
    return 1;
  return cntdeg(&T[t->rit]) + 1;
}

int cntdpt(T_node *t){
  if(t->par >= 0)
    return cntdpt(&T[t->par]) + 1;
  else
    return 0;
}
  
int gethig(T_node *t, int hig){
  if(t->lft < 0)
    return hig;
  int lhi = gethig(&T[t->lft], hig + 1), rhi = -1;
  if(T[t->lft].rit >= 0)
    rhi = gethig(&T[T[t->lft].rit], hig + 1);
  return rhi < lhi ? lhi : rhi;
}
