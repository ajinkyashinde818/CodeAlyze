#include <stdio.h>
#define MAX 100000

int height(int);

struct Node{
  int p;
  int s;
  int l;
  int r;
};

struct Node T[MAX];

int main(void){
  int n,i,j,left,right,c[MAX];
  int id[MAX],p,s,deg[MAX],dep,h[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    T[i].p = -1;
    T[i].s = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d",&id[i]);
    for(j = 0 ; j < 2 ; j++){
      scanf("%d",&c[j]);
      if(j == 0){
	left = c[j];
	T[id[i]].l = c[j];
	T[c[j]].p = id[i];
      }
      else {
	right = c[j];
	T[id[i]].r = c[j];
	T[c[j]].p = id[i];
      }
      
      if((c[0] == -1) && (c[1] == -1)) deg[id[i]] = 0;
      else if((c[0] != -1) && (c[1] != -1)) deg[id[i]] = 2;
      else deg[id[i]] = 1;
      
    }   
    T[left].s = right;
    T[right].s = left;
  }
  
  for(i = 0 ; i < n ; i++){
    h[i] = height(i);
  }
  
  for(i = 0 ; i < n ; i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].p);
    printf("sibling = %d, ",T[i].s);
    
    printf("degree = %d, ",deg[i]);
    
    id[i] = i;
    
    for(dep = 0 ; T[id[i]].p != -1 ; dep++){
      id[i] = T[id[i]].p;
    }   
    printf("depth = %d, ",dep);
       
    printf("height = %d, ",h[i]);
       
    if(T[i].p == -1){
      printf("root\n");
    }
    else if((T[i].p != -1) && ((T[i].l != -1) || (T[i].r != -1))){
      printf("internal node\n");
    }
    else if((T[i].l == -1) && (T[i].r == -1)){
      printf("leaf\n");
    }
  }

  return 0; 
}
 
int height(int i){
  int hl=0,hr=0;
  
  if((T[i].l == -1) && (T[i].r == -1)){
    return 0;
  }
  if(T[i].l != -1){
    hl = height(T[i].l);
  }
  if(T[i].r != -1){
    hr = height(T[i].r);
  }
  if(hl > hr){
    return hl+1;
  }
  else {
    return hr+1;
  }
}
