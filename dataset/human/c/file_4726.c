#include <stdio.h>

typedef struct{
  int p;
  int l;
  int r;
}Tree;

int n;

void output(Tree *);
int makedepth(Tree *,int);
int makeheight(Tree *,int);
  
int main(){
  Tree a[25];
  int d[25];
  int b,i,id,l,r;

  scanf("%d",&n);
   for(i = 0; i < n; i++){
    a[i].p = a[i].l = a[i].r = -1;
   }
   
  for(i = 0; i < n; i++){
    scanf("%d",&id);
    scanf("%d%d",&a[id].l,&a[id].r);
    if(a[id].l != -1)a[a[id].l].p = id;
    if(a[id].r != -1)a[a[id].r].p = id;
  }
  
  for(i = 0; i < n; i++){
   if(a[i].p == -1){
   r = i;
   break;
   }
  }
 output(a);
  return 0;
}

void output(Tree a[]){
  int i,b,prev,degree = 0,sibling = 0;
  
  for(i = 0; i < n; i++){
    prev = a[i].p;
    degree = 0;
    
    if(a[i].p != -1){
      if(a[prev].l == i)sibling = a[prev].r;
      else sibling = a[prev].l;
    }
    else{
     sibling = -1;
    }
    if(a[i].l != -1)degree++;
    if(a[i].r != -1)degree++;
    
    printf("node %d: parent = %d, ",i,a[i].p);
    printf("sibling = %d, degree = %d, ",sibling,degree);
    printf("depth = %d, height = %d, ",makedepth(a,i),makeheight(a,i));
    
    if(a[i].p == -1)printf("root\n");
    else if(a[i].l == -1 && a[i].r == -1)printf("leaf\n");
    else printf("internal node\n");
	   
  }
}

int makedepth(Tree a[],int d){
  int prev,num = 0;

  prev = d;
  while(a[prev].p != -1){
    num++;
    prev = a[prev].p;
  }
  return num;
}
 
int makeheight(Tree a[],int h){
  int result,num1 = 0,num2 = 0;

  if(a[h].l != -1)num1 = makeheight(a,a[h].l) + 1;
  if(a[h].r != -1)num2 = makeheight(a,a[h].r) + 1;

  if(num1 >= num2)result = num1;
  else result = num2;

  num1 = 0;
  num2 = 0;
  
  return result;
}
