#include <stdio.h>

int p[100000],l[100000],r[100000],d[100000],h[100000];

void depth(int x,int dep){
  d[x]=dep;
  if(r[x]!= -1)depth(r[x],dep+1);
  if(l[x]!= -1)depth(l[x],dep+1);
}

int height(int x){
  int h1=0,h2=0;

  if(l[x]!=-1)h1=height(l[x])+1;
  if(r[x]!=-1)h2=height(r[x])+1;

  if(h1>h2){
    h[x]=h1;
    return h1;
  }
  else{
    h[x]=h2;
    return h2;
  }
}

int main(){
  int i,j,n,t,t1,t2,t3,root;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    p[i]=-1;
    l[i]=-1;
    r[i]=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&t1,&t2,&t3);
    l[t1]=t2;
    r[t1]=t3;
    if(t2!=-1)p[t2]=t1;
    if(t3!=-1)p[t3]=t1;
  }

  /*for(i=0;i<n;i++){
    printf("%d\n",p[i]);
    }*/

  for(i=0;i<n;i++){
    if(p[i]==-1){
      root=i;
      break;
    }
  }
  //printf("ttt\n");

  depth(root,0);
  //printf("ttt2\n");
  height(root);
  //printf("ttt3\n");

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,p[i]);


    //sibling
    printf("sibling = ");
    if(p[i]==-1)printf("-1, ");
    else {
      t1=p[i];
      if(l[t1]==i)printf("%d, ",r[t1]);
      else printf("%d, ",l[t1]);
    }

    //degree
    t1=0;
    if(l[i]!=-1)t1++;
    if(r[i]!=-1)t1++;
    printf("degree = %d, ",t1);

    
    printf("depth = %d, ",d[i]);

    //height
    printf("height = %d, ",h[i]);

    
    if(p[i]==-1)printf("root");
    else if(l[i]==-1 && r[i]==-1)printf("leaf");
    else printf("internal node");
    /*t=l[i];
    for(j=0;t != -10;t=r[t]){
      if(j!=0){
	printf(", ");
      }
      j=1;
      printf("%d",t);
    }
    */
    printf("\n");
  }

  return 0;
}
