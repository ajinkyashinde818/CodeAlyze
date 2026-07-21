#include <stdio.h>
#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node ori[10000];

int getheight(int );
void result(int );

int main()
{
  int n,i,id,left,right;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    ori[i].p=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    ori[id].l=left;
    ori[id].r=right;
    if(left!=NIL && right!=NIL){
      ori[left].p=id;
      ori[right].p=id;
    }
    else if(left!=NIL && right==NIL){
      ori[left].p=id;
    }

    else if(left==NIL && right!=NIL){
      ori[right].p=id;
    }
  }
    
    for(i=0;i<n;i++) result(i);
  
    return 0;
}

int getheight(int i)
{
  int s=0,t=0;

  if(ori[i].l==NIL && ori[i].r==NIL) return 0;

  if(ori[i].l!=NIL){
    s=getheight(ori[i].l)+1;
  }

   if(ori[i].r!=NIL){
    t=getheight(ori[i].r)+1;
  }

   if(s>t)return s;

   else return t;
}

void result(int i)
{
  int count,height=0,depth=0,degree=0;
   printf("node %d: parent = %d, ",i,ori[i].p);
    if(ori[i].p==NIL){
      printf("sibling = -1, ");
    }

    else if(ori[ori[i].p].l==i){
      printf("sibling = %d, ",ori[ori[i].p].r);
    }

    else {
      printf("sibling = %d, ",ori[ori[i].p].l);
    }

    printf("degree = ");

    if(ori[i].l!=NIL && ori[i].r!=NIL){
      printf("2, ");
    }
      
      else if(ori[i].l==NIL && ori[i].r==NIL){
	printf("0, ");
      }

      else printf("1, ");

      count=i;

      while(ori[count].p!=NIL){
	depth++;
	count=ori[count].p;
      }

      printf("depth = %d, ",depth);
      depth=0;

      printf("height = ");
      height=getheight(i);

      printf("%d,",height);

      if(ori[i].p==NIL){
	printf(" root\n");
      }
      else if(ori[i].l==NIL && ori[i].r==NIL){
	printf(" leaf\n");
      }
      else {
	printf(" internal node\n");
      }
}
