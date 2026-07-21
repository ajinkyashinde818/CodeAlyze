#include <stdio.h>

typedef struct{
  int parent;
  int left;//left child
  int right;//right child
}BTree;

int Searcheight(int);

BTree t[25];

int main(){
  int n,i,id;
  int sib,deg,dep,tn,prov,height;
  char type[3][15]={"root","internal node","leaf"};
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    t[i].parent=-1;
    t[i].left=-1;
    t[i].right=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&t[id].left);
    scanf("%d",&t[id].right);
    t[t[id].left].parent=id;
    t[t[id].right].parent=id;
  }
  
  for(i=0;i<n;i++){
    //sibling
    if(t[i].parent==-1)
      sib=-1;
    else if(t[t[i].parent].left!=i)
      sib=t[t[i].parent].left;
    else if(t[t[i].parent].right!=i)
      sib=t[t[i].parent].right;
    else
      sib=-1;
    //end of sibling
    //degree
    deg=0;
    if(t[i].right!=-1)
      deg++;
    if(t[i].left!=-1)
      deg++;
    //end of degree
    //depth
    dep=0;
    prov=t[i].parent;
    while(prov!=-1){
      prov=t[prov].parent;
      dep++;
    }
    //end of depth
    //height
    height=0;
    height=Searcheight(i);
    //end of height
    //type
    if(dep==0)
      tn=0;
    else if(t[i].right!=-1||t[i].left!=-1)
      tn=1;
    else
      tn=2;
    //end of type
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,t[i].parent,sib,deg,dep,height,type[tn]);
  }
  return 0;
}

int Searcheight(int i){//saiki
  int r,l,height;
  if(t[i].right!=-1)
    r=Searcheight(t[i].right)+1;
  else
    r=0;
  if(t[i].left!=-1)
    l=Searcheight(t[i].left)+1;
  else
    l=0;
  if(r>l)
    height=r;
  else
    height=l;
  return height;
}
