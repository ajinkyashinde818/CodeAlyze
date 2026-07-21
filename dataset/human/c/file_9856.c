#include<stdio.h>

#define max 100000

struct node{
  int p,left,right;
    };

struct node T[max];
int T2[max];

int recursive(int,int);
void printtree(int);

int recursive(int u,int p)
{
  T2[u] = p;
  if(T[u].right != -1)
    recursive(T[u].right,p);
  if(T[u].left != -1)
    recursive(T[u].left,p+1);
}

void printtree(int u)
{
  int i,cn;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",T2[u]);

  if(T[u].p == -1) {
    printf("root, ");
  }else if(T[u].left == -1) {
    printf("leaf, ");
  }else{
    printf("internal node, ");
  }

  printf("[");

  for(i=0,cn=T[u].left;cn!=-1;i++,cn=T[cn].right) {
    if(i){
      printf(", ");
    }
    printf("%d",cn);
  }

  printf("]\n");
}


int main()
{

  int i,j,n;
  int dep,high,cn,lef,rig; /* dep 深さ high 高さ cn 子 lef 左 rig 右*/


  scanf("%d",&n);

  for(i=0;i<n;i++) {
    T[i].p = -1;
    T[i].left = -1;
    T[i].right = -1;
  }
  

  for(i=0;i<n;i++) {
    scanf("%d%d",&high,&dep);
      for(j=0;j<dep;j++) {
         scanf("%d",&cn);
	 if(j == 0) {
	   T[high].left = cn;
	 }else{
	   T[lef].right = cn;
	 }
	 lef = cn;
	 T[cn].p = high;
      }
  }

  for(i=0;i<n;i++) {
    if(T[i].p == -1)
      rig = i;
  }
  
  recursive(rig,0);

  for(i=0;i<n;i++)
    printtree(i);

  return 0;

}
