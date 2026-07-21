#include<stdio.h>
#define LEN 25
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}Tree;

Tree t[25];
int n;
int Depth[25],Height[25];

int calHeight(int key);
void calDepth(int key,int depth);
int findsibling(int key);
void print(void);

int main(){
  int i,j;
  int root,r,l,key;

  //in
  scanf("%d",&n);

  //ini
  for(i=0;i<n;i++)
    t[i].parent=t[i].left=t[i].right=NIL;

  //in
  for(i=0;i<n;i++){
    scanf("%d%d%d",&key,&l,&r);
    t[key].left=l;
    t[key].right=r;
    if(l!=NIL) t[l].parent=key;
    if(r!=NIL) t[r].parent=key;
  }

  //findroot
  for(i=0;i<n;i++)
    if(t[i].parent==NIL){
      root=i;
      break;
    }

  calHeight(root);
  calDepth(root,0);

  print();

  return 0;
}

int calHeight(int key){
  int h1=0,h2=0;
  
  if(t[key].left!=NIL)
    h1=calHeight(t[key].left)+1;
  if(t[key].right!=NIL)
    h2=calHeight(t[key].right)+1;

  return Height[key]=( h1>h2 ? h1 : h2 );
}
void calDepth(int key,int depth){
  Depth[key]=( Depth[key]>depth ? Depth[key] : depth);

  if(t[key].left!=NIL)
    calDepth(t[key].left,depth+1);
  if(t[key].right!=NIL)
    calDepth(t[key].right,depth+1);
}
int findsibling(int key){

  if(t[key].parent==NIL)return NIL;

  if(t[t[key].parent].left != key && t[t[key].parent].left != NIL)
    return t[t[key].parent].left;
  if(t[t[key].parent].right != key && t[t[key].parent].right != NIL)
    return t[t[key].parent].right;

  return NIL;
}
void print(void){
  int i,j,k;
  int l,tmp;
  int degree;
  
  for(i=0;i<n;i++){
    degree=0;
    if(t[i].left!=NIL)degree++;
    if(t[i].right!=NIL)degree++;
    
    printf("node %d: ",i);
    printf("parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",t[i].parent,findsibling(i),degree,Depth[i],Height[i]);

    if(t[i].parent==NIL)
      printf("root");
    else if(t[i].left!=NIL || t[i].right!=NIL)
      printf("internal node");
    else 
     printf("leaf");

    printf("\n");
  }
}
