#include<stdio.h>
 
typedef struct {
  int left;
  int right;
  int p;
} node;
 
node a[10000];
int b[10000], c[10000], n;
 
void x(int d,int e)
{
  
  if(d==-1) return;
  
  b[d] = e;
  x(a[d].left,e+1);
  x(a[d].right,e+1);
  
}
 
int y(int d)
{
  
  int e, f;

  e = 0;
  f = 0;
  
  if (a[d].left!=-1){
    e = y(a[d].left)+1;
  }
  
  if (a[d].right!=-1) {
    f = y(a[d].right)+1;
  }
  
  return c[d]=(e>f ? e:f);
  
}
 
int z(int d) {
  
  if(a[d].p==-1) return -1;
  
  if(a[a[d].p].left!=d && a[a[d].p].left!=-1) return a[a[d].p].left;
  
  if (a[a[d].p].right!=d && a[a[d].p].right!=-1) return a[a[d].p].right;
  
  return -1;
  
}
 
 
int main()
{
  
  int i, id, l, r, root, deg;

  root = 0;
  
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    a[i].p = -1;
  }
 
  for (i=0;i<n;i++){
    scanf("%d %d %d",&id,&l,&r);
    a[id].left = l;
    a[id].right = r;
    if(l!=-1){
      a[l].p = id;
    }
    if(r!=-1){
      a[r].p = id;
    }
  }
 
  for(i=0;i<n;i++){
    if(a[i].p==-1){
      root = i;
    }
  }
 
  x(root,0);
  y(root);
 
  for(i=0;i<n;i++){
    deg = 0; 
    printf("node %d: ",i);
    printf("parent = %d, ",a[i].p);
    printf("sibling = %d, ",z(i));
    if(a[i].left!=-1){
      deg++;
    }
    if(a[i].right!=-1){
      deg++;
    }
    printf("degree = %d, ",deg);
    printf("depth = %d, ",b[i]);
    printf("height = %d, ",c[i]);
    if(a[i].p==-1){
      printf("root\n");
    }
    else if(a[i].left==-1 && a[i].right==-1){
      printf("leaf\n");
    }
    else{
      printf("internal node\n");
    }
  }

  return 0;
  
}
