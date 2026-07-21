#include <stdio.h>

void depth(int,int);
void height(int,int);

int d[25],s[25],c[25][2],p[25],h[25],hh,root;

int main()
{
  int n,i,j,id,type[25],left,right,hig=0;

  scanf("%d",&n);

  for(j=0;j<n;j++){
    c[j][0]=-1;
    c[j][1]=-1;
    p[j]=-1;
    s[j]=-1;
  }

  for(j=0;j<n;j++){
    scanf("%d",&id);
    scanf("%d %d",&left,&right);

    if(left!=-1){
      s[left]=right;
      p[left] = id;
    }
    if(right!=-1){
      s[right]=left;
      p[right] = id;
    }
    c[id][0]=left;
    c[id][1]=right;
  } 

  /*type*/
  for(j=0;j<n;j++){
    if(p[j]==-1) {
      root=j;
      type[j] = 0;
    }
    else if(c[j][0]==-1&&c[j][1]==-1) type[j] = 1;
    else type[j] = 2;
  }

  depth(root,0);
  
  for(j=0;j<n;j++){
    hh=0;
    height(j,0);
    h[j]=hh;
  }

  /* ??¨??? */
  for(j=0;j<n;j++){
    printf("node %d: parent = %d, sibling = %d, ",j,p[j],s[j]);

    printf("degree = ");

    if(type[j]==1||n==1){
      printf("0, ");
    }
    else if(c[j][0]!=-1&&c[j][1]!=-1)printf("2, ");
    else printf("1, ");

    printf("depth = %d, ",d[j]);
    printf("height = %d, ",h[j]);

    if(type[j]==0) printf("root\n");
    else if(type[j]==1) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}

void depth(int id,int dep){
  d[root]=0;
  if(c[id][0]==-1&&c[id][1]==-1) return;
  dep++;
  if(c[id][0]==-1) {
    d[c[id][1]]=dep;
    depth(c[id][1],dep);
  }
  else if(c[id][1]==-1)   {
    d[c[id][0]]=dep;
    depth(c[id][0],dep);
  }
  else{
    d[c[id][0]]=dep;
    d[c[id][1]]=dep;

    depth(c[id][0],dep);
    depth(c[id][1],dep);
  }
}

void height(int id,int hig){
  if(c[id][0]==-1&&c[id][1]==-1) return;
  hig++;
  if(hh<=hig) hh=hig;

  if(c[id][1]==-1) height(c[id][0],hig);
  else if(c[id][0]==-1)  height(c[id][1],hig);
  else{
    height(c[id][0],hig);
    height(c[id][1],hig);
  }
}
