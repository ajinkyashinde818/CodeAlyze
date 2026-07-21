#include <stdio.h>
typedef struct {/*parent,left child ,right sibling*/
int p,l,r;
} node;
int degree(int );
int height(int );
int depth(int );
int sibling(int );
void Print(int );
node T[100000];
int main()
{
int n,i,id,l,r;
scanf("%d",&n);

for(i=0;i<n;i++)
{
T[i].p = T[i].l = T[i].r = -1;
}

for(i=0;i<n;i++)
{
scanf("%d%d%d",&id,&l,&r);
T[id].l = l;
T[id].r = r;
T[l].p = id;
T[r].p = id;
}

for(i=0;i<n;i++)
{
Print(i);
}
return 0;
}

int depth(int id)
{
  if(T[id].p == -1) return 0;
  return 1+depth(T[id].p);
}

int degree(int id)
{
if(T[id].l != -1 && T[id].r != -1)  return 2;
else if(T[id].l != -1 || T[id].r != -1) return 1;
else return 0;
}
int height(int id)
{
int leftHigh=0,rightHigh=0;
if(id== -1) return 0;
if (T[id].l != -1) leftHigh = height(T[id].l)+1;
if(T[id].r != -1) rightHigh = height(T[id].r)+1;

if(rightHigh < leftHigh) return leftHigh;
else return rightHigh;
}
int sibling(int id)
{
int parent = T[id].p;
if(T[id].p == -1) return -1;
else if(T[parent].l != id) return T[parent].l;
else return T[parent].r;
}
void Print(int id)
{
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",id,T[id].p,sibling(id),degree(id),depth(id),height(id));
  if(T[id].p == -1) printf("root\n");
  else if(T[id].l == -1 && T[id].r == -1) printf("leaf\n");
  else printf("internal node\n");
}
