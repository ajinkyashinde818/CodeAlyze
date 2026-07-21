#include<stdio.h>
#define NIL -1
#define MAX 25
typedef struct {
  int parent;
  int leftc;
  int rightc;
}Node;
Node t[MAX];
int h,max;
void calcHeight(int);

int main() {
  int i,j,n,id,left,right;
  int depth[MAX],height[MAX],sibling[MAX],degree[MAX];

  scanf("%d",&n);
  for(i=0; i<n; i++) {
    t[i].parent=t[i].leftc=t[i].rightc=sibling[i]=NIL;
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
    t[id].leftc = left;
    t[id].rightc = right;
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
    else if(t[i].leftc!=-1 || t[i].rightc!=-1) printf("internal node");
    else printf("leaf");
    printf("\n");
  }
  return 0;
}


void calcHeight(int n)
{
  if(t[n].leftc==NIL || t[n].rightc==NIL)  max = h>max ? h:max;
  if(t[n].leftc!=NIL) {
    h++;
    calcHeight(t[n].leftc);
  }
  if(t[n].rightc!=NIL) {
    h++;
    calcHeight(t[n].rightc);
  }
  h-=1;
}
