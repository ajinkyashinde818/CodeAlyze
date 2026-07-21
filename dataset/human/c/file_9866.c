#include<stdio.h>
#include<stdlib.h>

#define N 100000

/*?????????????????????*/
typedef struct {
  int  parent;
  int  left;
  int  right;
}NODE;
  
NODE T[N];


int calc_depth(int);
int degree(int); //?¬???°
 
main(){
  int i,j,child,n,id,k,l;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      T[i].parent = -1;
      T[i].left = -1;
      T[i].right = -1;
    } //??????
  
  for(i = 0; i < n; i++)
    {
      scanf("%d%d",&id, &k);
      
      for(j = 0; j < k; j++){
	scanf("%d", &child);
	T[child].parent = id;
	if(j == 0){
	  T[id].left = child;
	}
	else{
	  T[l].right = child;
	}
	l = child;
       
      }
    }
  
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, calc_depth(i));
    
    if(T[i].parent == -1){
      printf("root, [");
    }
    
    else if(T[i].left == -1){
      printf("leaf, [");
    }
    
    else{
      printf("internal node, [");
    }
    
    degree(T[i].left);
    printf("]\n");
  }
  
  return 0;
}



int calc_depth(int i){
  int c = 0;
  if(T[i].parent == -1)
    {
      return 0;
    }
  else {
    c = calc_depth(T[i].parent) + 1;
    return c;
  }
}
  
int degree(int a){
  if(a == -1){
    return 0;
  }
  else {
    if(T[a].right == -1){
      printf("%d",a); 
    }
    else{
      printf("%d, ",a);
      degree(T[a].right);
    }
  }
}
