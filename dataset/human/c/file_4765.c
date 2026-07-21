#include <stdio.h>

#define N 100000

typedef struct{
  int p;
  int l;
  int r;
}Node;

int Height(Node*, int);

int main(){

   int i;
   int j;
   int n;
   int id;
   int left;
   int right;
   int depth;
   int sibling;
   int degree;
   int height;
  Node T[N];

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&T[id].l,&T[id].r);
    T[T[id].l].p = id;
    T[T[id].r].p = id;
   }
  
    for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,T[i].p);


    sibling =-1;
    
    if(T[i].p!=-1){
         if(T[T[i].p].l != i && T[T[i].p].l != -1) sibling =  T[T[i].p].l;
    else if(T[T[i].p].r != i && T[T[i].p].r != -1) sibling =  T[T[i].p].r;
    }
    
    printf("sibling = %d, ",sibling);

    degree = 0;
    if(T[i].l!=-1) degree++;
    if(T[i].r!=-1) degree++;

    printf("degree = %d, ",degree);
    
        depth=0;
        id=i;
        while(T[id].p != -1){
            depth++;
            id=T[id].p;
        }
        printf("depth = %d, ",depth);

	height = Height(T,i);
	printf("height = %d, ",height);
	
        if(T[i].p==-1) printf("root\n");
        else if(T[i].l==-1 && T[i].r==-1) printf("leaf\n");
        else printf("internal node\n");
 }
  
  return 0;
}

int Height(Node *T, int i){

  int left=0;
  int right=0;
  
    if (T[i].r == -1 && T[i].l == -1) return 0;
    if (T[i].l != -1){
      left =  Height(T,T[i].l)+1;
    }
    if(T[i].r != -1){
      right =  Height(T,T[i].r)+1;
    }
    if(left > right) return left; 
     
    else return right; 
}
