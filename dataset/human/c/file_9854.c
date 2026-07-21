#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

struct Node{
  int p;
  int l;
  int r;
  int o;
};

struct Node T[MAX];

int main(void){
  int n,i,j,id,k[MAX],c,d,l;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
    
  for(i = 0 ; i < n ; i++){
    scanf("%d",&id);
    scanf("%d",&k[i]);
    T[id].o = k[i];
    
    if(T[id].o != 0){
      for(j = 0 ; j < T[id].o ; j++){
	scanf("%d",&c);
	
	if(j == 0){
	  T[id].l = c;
	  l = c;
	  T[c].p = id;
	}
	else {
	  T[l].r = c;
	  l = c;
	  T[c].p = id;
	}   
      }
    }
  }
 
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, ",i,T[i].p);

    id = i; 
    T[i].o = T[id].o;

    for(d = 0 ; T[id].p != -1 ; d++){
      id = T[id].p;
    }

    printf("depth = %d, ",d);
    
    if(T[i].p == -1){
      printf("root, ");
    }
    else if((T[i].p != -1) && (T[i].l != -1)){
      printf("internal node, ");
    }
    else if(T[i].l == -1){
      printf("leaf, ");
    }

    
    if(T[i].o != 0){

      if(T[i].o == 1){
	printf("[%d]\n",T[i].l);
      }
      else {
	printf("[%d, ",T[i].l);
	for(l = T[i].l ; T[l].r != -1 ;){
	  printf("%d",T[l].r);
	  l = T[l].r;
	  if(T[l].r != -1) printf(", ");
	}
	printf("]\n");
      }
    }
    else {
      printf("[]\n");
    }

  }
  return 0;
}
