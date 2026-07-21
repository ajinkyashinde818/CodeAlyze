#include<stdio.h>

int did[100001];

void search(int a[],int c,int x){

  if(x==2){
    printf("%d\n",c);
    return;
  }
  if(did[x]==1){
    printf("-1\n");
    return;
  }
  did[x]=1;

  search(a,c+1,a[x]);
}



int main(void){
  int a[100001];
  int i,j,m,n;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    did[i]=0;
    scanf("%d",&a[i]);
  }

  search(a,0,1);

  return 0;
}
