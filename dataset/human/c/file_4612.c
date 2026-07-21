#include<stdio.h>
#define NIL -1

int FindDepth(int);

int FindHeight(int);
int FindSib(int);
typedef struct{
  int parent;
  int left;
  int right;
}vertex;
void output(int);
vertex V[25];
int ver[25],D[25];
int n;
int FHd=0;
main()
{
  int i,childleft,childright;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      V[i].parent = V[i].left = V[i].right = NIL;
    }

  for(i=0;i<n;i++)
    {
      scanf("%d",&ver[i]);/*ver[i]????????????????????\???*/
      if(i == 0){
	V[ver[i]].parent=NIL;/*root?????´???*/
      }
     
      scanf("%d",&V[ver[i]].left);/*root???parent??\???????????§???-1?????\??£??????*/
      scanf("%d",&V[ver[i]].right);

      childleft = V[ver[i]].left;
      childright = V[ver[i]].right;
      V[childleft].parent = V[childright].parent = ver[i];

    }/*??\?????????*/

  for(i=0;i<n;i++){
    D[i]=FindDepth(i);
  }
  for(i=0;i<n;i++){
   
      output(i);
      
  }
  return 0;

}

int FindDepth(int i)
{
  int d = 0,u = 0;
  while(1){

    if(V[i].parent == NIL)break;
    d++;
    i = V[i].parent;
  }
  return d;
}

int FindHeight(int i)
{
  int RightHeight=0,LeftHeight=0;
  
 
  if( V[i].left == NIL && V[i].right == NIL )return 0;
    if(V[i].left!=NIL)LeftHeight = FindHeight(V[i].left)+1; 
    if(V[i].right!=NIL)RightHeight = FindHeight(V[i].right)+1;
   
    if(RightHeight>LeftHeight)return RightHeight;
    else return LeftHeight;
  
}

int FindSib(int i){
  int k;
  k = V[i].parent;
  if(k==-1)return NIL;
  if(i==V[k].left)return V[k].right;
  else if(i==V[k].right)return V[k].left;
  else if(V[k].right==NIL && V[k].left==NIL)return NIL;
}

void output(int p)
{
  
  printf("node %d: parent = %d, sibling = %d, degree = ",p,V[p].parent,FindSib(p));
  if(V[p].left ==NIL && V[p].right ==NIL)printf("0, ");
  else if(V[p].left == NIL || V[p].right == NIL)printf("1, ");
  else printf("2, ");

  printf("depth = %d, height = %d, ",D[p],FindHeight(p));

  if(V[p].left == NIL && V[p].right == NIL && V[p].parent!=NIL)printf("leaf\n");
  else if(V[p].parent == NIL)printf("root\n");
  else printf("internal node\n");
}
