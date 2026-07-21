#include<stdio.h>
#define N 26

typedef struct
{
  int par;         //親
  int left;
  int right;
  int sib;
}Binary;

int n,dep[N],hei[N];
Binary B[N];

void Depth(void);
void Print(void);
int Height(int);

int main()
{
  int i,id,l,r,root;
  scanf("%d",&n);
  for(i=0;i<n;i++) B[i].par = B[i].left = B[i].right = B[i].sib = -1;  //初期化

  for(i=0;i<n;i++)                      //n回ループ
  {
    scanf("%d%d%d",&id,&l,&r);     //id:節点,left:左の子の番号,right:右の子
    B[id].left = l;
    B[id].right = r;
    if(l!=-1)B[l].par = id;
    if(r!=-1)B[r].par = id;
    if(l!=-1)B[l].sib = B[id].right;           //deg
    if(r!=-1)B[r].sib = B[id].left;           //deg*/
  }
  for(i=0;i<n;i++)  if(B[i].par == -1) hei[i] = Height(i);
  Depth();
  Print();

  return 0;
}

void Depth(void)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    j=i;
    while(B[j].par != -1)
    {
      dep[i]++;
      j = B[j].par;
    }
  }
}

void Print(void)
{
  int i,deg=0;
  for(i=0;i<n;i++)
  {
    deg=0;
    printf("node %d: ",i);
    printf("parent = %d, ",B[i].par);
    printf("sibling = %d, ",B[i].sib);
    if(B[i].left != -1)deg++;
    if(B[i].right != -1)deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",dep[i]);
    printf("height = %d, ",hei[i]);
    if(B[i].par == -1)printf("root\n");
    else if(hei[i] == 0)printf("leaf\n");
    else printf("internal node\n");
  }
}

int Height(int i)
{
  int hei1 = 0, hei2 = 0;
  if(B[i].left != -1) hei1= Height(B[i].left)+1;
  if(B[i].right != -1)hei2 = Height(B[i].right)+1;

  return hei[i] = hei1 > hei2 ? hei1 : hei2;
}
