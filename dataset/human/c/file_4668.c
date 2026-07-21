#include<stdio.h>
#define N 100000

typedef struct{
  int pare,fstch,sibling;
}Node;

Node node[N];
int n,dep[N],he[N];

int sibling(int x){
    if(node[x].pare == -1)
        return -1;
    if(node[node[x].pare].fstch != x && node[node[x].pare].fstch != -1)
        return node[node[x].pare].fstch ;
    if(node[node[x].pare].sibling != x && node[node[x].pare].sibling != -1)
        return node[node[x].pare].sibling;
    return -1;
}

void print(int x){
    int d=0;
    
    printf("node %d: ",x);
    printf("parent = %d, ",node[x].pare);
    printf("sibling = %d, ",sibling(x));

    if(node[x].fstch != -1)
        d++;
    if(node[x].sibling != -1)
        d++;
    printf("degree = %d, ",d);
    printf("depth = %d, ",dep[x]);
    printf("height = %d, ",he[x]);

    if(node[x].pare == -1)
        printf("root\n");
    else if(node[x].fstch == -1 && node[x].sibling == -1)
        printf("leaf\n");
    else
        printf("internal node\n");
}

void depth(int x,int cnt){
  if(x==-1) return;
  
  dep[x]=cnt;
  depth(node[x].fstch,cnt+1);
  depth(node[x].sibling,cnt+1);
}

int height(int x){
    int h1=0,h2=0;
    if(node[x].fstch != -1)
        h1=height(node[x].fstch)+1;
    if(node[x].sibling != -1)
        h2=height(node[x].sibling)+1;
    return he[x]=(h1>h2?h1:h2);
}


int main(){

  int i,j,ch,v,left,right,root,k;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    node[i].pare = node[i].fstch = node[i].sibling = -1;

  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&left,&right);

    node[v].fstch=left;
    node[v].sibling=right;
    
    if(left!=-1) node[left].pare=v;
    if(right!=-1) node[right].pare=v;
  }

  for(k=0;k<n;k++){
    if(node[k].pare==-1)
      root=k;
  }

  depth(root,0);
  height(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}
