#include<stdio.h>

#define N 100000
#define NIL -1

int depth(int);
int height(int);

struct Node{
    int pa;
    int le;
    int ri;
};

struct Node Te[N];

int main(){
  int n,i,id;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    Te[i].pa=Te[i].le=Te[i].ri=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&Te[id].le,&Te[id].ri);
    if(Te[id].le!=NIL) Te[Te[id].le].pa=id;
    if(Te[id].ri!=NIL) Te[Te[id].ri].pa=id;
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = ",i,Te[i].pa);
    if(Te[i].pa==NIL) printf("-1, ");
    else{
      if(Te[Te[i].pa].le==i) printf("%d, ",Te[Te[i].pa].ri);
      else printf("%d, ",Te[Te[i].pa].le);
      }
      printf("degree = ");
      if(Te[i].le==NIL && Te[i].ri==NIL) printf("0, ");
      else{
        if(Te[i].le!=NIL && Te[i].ri!=NIL) printf("2, ");
        else printf("1, ");
      }
      printf("depth = %d, height = %d, ",depth(i),height(i));
        if(Te[i].pa==NIL) printf("root");
        else{
          if(Te[i].le==NIL && Te[i].ri==NIL) printf("leaf");
          else printf("internal node");
        }
        printf("\n");
      }
      return 0;
    }

int depth(int x){
  if(Te[x].pa==NIL) return 0;
  return depth(Te[x].pa)+1;
}

int height(int x){
  int left=0,right=0;
  if(Te[x].le==NIL && Te[x].ri==NIL) return 0;
  if(Te[x].le!=NIL) left=height(Te[x].le)+1;
  if(Te[x].ri!=NIL) right=height(Te[x].ri)+1;
  if(left>right) return left;
  else return right;
}
