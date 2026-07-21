#include <stdio.h>
#define N 25
#define Q -1
typedef struct{
  int p;
  int l;
  int r;
}Tree;
Tree tree[N];
int D[N],H[N];
void Depth(int st,int de);
int Height(int st);
int Setsu (int st);
void P (int st);

int main()
{
  int i,n,m,le,ri;
  int squrt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    tree[i].p=-1;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&m,&le,&ri);
    tree[m].l=le;
      tree[m].r=ri;
      if(le!=-1)
	tree[le].p=m;
      if(ri!=-1)
	tree[ri].p=m;
  }
  for(i=0;i<n;i++)
    if(tree[i].p==-1)
      squrt=i;

  Depth(squrt,0);
  Height(squrt);

  for(i=0;i<n;i++)
    P(i);
  
  return 0;
}
void Depth(int st,int de){
  if (st == -1)
    return;
  D[st]= de;
  Depth (tree[st].l,de+1);
  Depth (tree[st].r,de+1);
}

int Height(int st){
  int a=0,b=0;
  if(tree[st].l!=-1)
    a=Height(tree[st].l)+1;
  if(tree[st].r!=-1)
    b=Height(tree[st].r)+1;
  return H[st]=(a>b ? a:b);
}

int Setsu (int st){
  if(tree[st].p == -1)
    return -1;
  if(tree[tree[st].p].l!=st && tree[tree[st].p].l!=-1)
    return tree[tree[st].p].l;
  if(tree[tree[st].p].r!=st && tree[tree[st].p].r!=-1)
 return tree[tree[st].p].r;
  return -1;
}

void P (int st){
  int count=0;
  
  printf("node %d: parent = %d, sibling = %d, ",st,tree[st].p,Setsu(st));
  if(tree[st].l!=-1)
    count++;
  if(tree[st].r!=-1)
    count++;
  
  printf("degree = %d, depth = %d, height = %d, ",count,D[st],H[st]);

  if(tree[st].p ==-1){
    printf("root\n");
  }else if(tree[st].l==-1 &&tree[st].r==-1){
     printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}
