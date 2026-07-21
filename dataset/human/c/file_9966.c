#include<stdio.h>
#define N 100005

typedef struct
{
  int parent;
  int left;
  int right;
}rooted;

int n,dep[N];
rooted A[N];

void Print(int *);
void depth();

int main()
{
 int j,i,num,lim=0,c,left,right,k[N];
 scanf("%d",&n);            //節点の個数
 for(i=0;i<n;i++)     //初期化　
 {
  dep[i]=0;
  A[i].parent = A[i].left = A[i].right = -1;
 }

 for(j=0;j<n;j++)
 {
  scanf("%d",&num);        //node番号
  scanf("%d",&k[num]);          //子の数
  for(i=0;i<k[num];i++)
  {
   scanf("%d",&c);              //子の番号
   if(i == 0)A[num].left = c;
   else A[left].right=c;
   left = c;
   A[c].parent = num;
  }

 }
 depth();
 Print(k);

 return 0;
}


void Print(int *k)
{
  int j,i,c,s=0;
  for(j=0;j<n;j++)             //print
  {
    if(A[j].parent == -1)printf("node %d: parent = %d, depth = %d, root, [",j,A[j].parent,dep[j]);
    else if(k[j] != 0) printf("node %d: parent = %d, depth = %d, internal node, [",j,A[j].parent,dep[j]);
    else printf("node %d: parent = %d, depth = %d, leaf, [",j,A[j].parent,dep[j]);

    c = A[j].left;
    s=0;
    while(c!=-1)
    {
      if(s == 0)printf("%d",c);
      else printf(", %d",c);
      c = A[c].right;
      s++;
    }

    printf("]\n");
  }
}


void depth()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    j=i;
    while(A[j].parent != -1)
    {
      dep[i]++;
      j = A[j].parent;
    }
  }
}
