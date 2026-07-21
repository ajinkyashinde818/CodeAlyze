#include <stdio.h>
void getH(int,int);

typedef struct {
  int parent;
  int child;
  int brother;
  int child2;
  int deg;
} node;

node n[100000];
int H;
int main()
{
  int a,c,d,e,i,j,num,depth;
  scanf("%d", &num);
  for(i=0;i<num;i++){
    n[i].parent=-1;
    n[i].brother=-1;
 n[i].child=-1;
  }
  for(i=0;i<num;i++){

    scanf("%d",&a);
    n[a].deg=0;    
scanf("%d%d",&n[a].child,&n[a].child2);

    if(n[a].child2!=-1){
      n[n[a].child2].parent=a;
      n[n[a].child2].brother=n[a].child;
      n[a].deg++;
}
 if(n[a].child!=-1){
n[n[a].child].parent=a;
      n[n[a].child].brother=n[a].child2;
 n[a].deg++;
}

  }
  
for(i=0;i<num;i++){
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,n[i].parent,n[i].brother,n[i].deg);
    
c=n[i].parent;    
    depth=0;    
while(c!=-1){
depth++;
      c=n[c].parent;


}
    printf("depth = %d, ",depth);
    H=0;    
getH(i,0);
    printf("height = %d, ",H);    

if(n[i].parent==-1)
      printf("root\n");
    else if(n[i].child==-1&&n[i].child2==-1)printf("leaf\n");
    else printf("internal node\n");

 }

  

    return 0;
  }



void getH(int x,int h){
  if(x==-1)return;

  getH(n[x].child,h+1);
getH(n[x].child2,h+1);

 if(H<h)H=h;
}
