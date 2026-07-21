#include<stdio.h>

#define NIL -1
#define MAX 25

typedef struct {
  int parent;
  int le;
  int ri;
}Node;


Node t[MAX];
int h,max;
void calcHeight(int);
 
int main() {

int i,j,n,id,left,right;
int depth[MAX],height[MAX],sibling[MAX],degree[MAX];
 
  scanf("%d",&n);

  for(i=0; i<n; i++) {
    t[i].parent=t[i].le=t[i].ri=sibling[i]=NIL;
    degree[i]=0;
  }    

  for(i=0; i<n; i++) {
    scanf("%d%d%d",&id,&left,&right);
    if(left!=NIL) {
      t[left].parent=id;
      degree[id]++;
    }
    if(right!=NIL){
      t[right].parent=id;
      degree[id]++;
    }
    t[id].le = left;
    t[id].ri = right;
    sibling[left]=right;
    sibling[right]=left;
  }
 
  for(i=0; i<n; i++) {
    depth[i]=height[i]=0;
    j=i;
    while(t[j].parent!=NIL) {
      j=t[j].parent;
      depth[i]++;
    }
    max=h=0;
    calcHeight(i);
    height[i] = max;
  }
  for(i=0; i<n; i++) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,t[i].parent,sibling[i],degree[i],depth[i],height[i]);
    if(t[i].parent==-1) printf("root");
    else if(t[i].le!=-1 || t[i].ri!=-1) printf("internal node");
    else printf("leaf");
    printf("\n");
  }
  return 0;
}
 
 
void calcHeight(int n)
{
  if(t[n].le==NIL || t[n].ri==NIL)  max = h>max ? h:max;
  if(t[n].le!=NIL) {
    h++;
    calcHeight(t[n].le);
  }
  if(t[n].ri!=NIL) {
    h++;
    calcHeight(t[n].ri);
  }
  h-=1;
}
