#include<stdio.h>
#include<string.h>

int main(void){

  typedef struct Ryouri{
    int num;
    int manzoku;
    int tuika;

  }ryouri;

  int n;
  int i,j;
  int ans=0;
  scanf("%d",&n);

  ryouri ry[n];
  int order[n];

  for(i=0;i<n;i++){
    ry[i].num=i;
  }

  for(i=0;i<n;i++){
    scanf("%d",&order[i]);
    order[i]=order[i]-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&ry[i].manzoku);
  }
  for(i=0;i<n-1;i++){
    scanf("%d",&ry[i].tuika);
  }

  /*for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(ry[i].itu>ry[j].itu){
        tmp=ry[i];
        ry[i]=ry[j];
        ry[j]=tmp;
      }
    }
  }*/
  for(i=0;i<n;i++){
  ans=ans+ry[i].manzoku;
  }
  for(i=0;i<n-1;i++){

    if(ry[order[i]].num==ry[order[i+1]].num-1){
      ans=ans+ry[order[i]].tuika;
    }
  }
  printf("%d",ans);




return 0;

}
