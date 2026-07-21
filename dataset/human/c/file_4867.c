#include<stdio.h>
#define N 100000
int total,a[N],b[N],c[N];
int hukasa(int);
int height(int);
int main(int jeep,char *com[]){
  int i,j;
  scanf("%d",&total);
  for(i=0;i<total;i++){
    a[i]=-1;
    b[i]=-1;
    c[i]=0;
  }
  for(i=0;i<total;i++){
    int k,left,right;
    scanf("%d %d %d",&k,&left,&right);
    if(left!=-1){
      a[left]=k;
      b[left]=right;
      c[k]++;
    }
    if(right!=-1){
      a[right]=k;
      b[right]=left;
      c[k]++;
    }
  }
  for(i=0;i<total;i++){
    int d;
    d=hukasa(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,\
a[i],b[i],c[i],d,height(i));
    if(d==0){
      printf("root\n");}
    else if(c[i]==0){
      printf("leaf\n");}
    else{
      printf("internal node\n");
    }
  }
return 0;
}
int hukasa(int jeep){
  if(a[jeep]==-1)return 0;
  return hukasa(a[jeep])+1;
}
int height(int jeep){
  int j,divala=0,ryohu;
  for(j=0;j<total;j++){
    if(a[j]==jeep){
      ryohu=height(j)+1;
      if(ryohu>divala)
        divala=ryohu;
    }
  }
  return divala;
}
