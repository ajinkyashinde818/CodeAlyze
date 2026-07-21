#include<stdio.h>
int height(int);
//ST[1]は親はST[0]|は子の数
int ST[100000][2];
int ST2[100000][2];
int main(){
  int n,i,j,NN,MN,free;
  scanf("%d",&n);
  for(i=0;i<n;i++)ST2[i][1]=-1;
  for(i=0;i<n;i++){
    scanf("%d",&NN);
    MN=2;
    ST2[NN][0]=MN;
    for(j=0;j<MN;j++){
      scanf("%d",&free);
      ST[NN][j]=free;
      if(free==-1)continue;
      ST2[free][1]=NN;
    }
  }
  for(i=0;i<n;i++){
    j=i;
    free=0;
    printf("node %d: parent = %d,",i,ST2[i][1]);
    while(ST2[j][1]!=-1){
      j=ST2[j][1];
      free++;
    }
    printf(" sibling = ");
    if(ST2[i][1]==-1)printf("-1, ");
    else printf("%d, ",ST[ST2[i][1]][0]==i?ST[ST2[i][1]][1]:ST[ST2[i][1]][0]);
   
    printf("degree = ");
    if(ST[i][0]!=-1||ST[i][1]!=-1)
      if(ST[i][0]!=-1&&ST[i][1]!=-1)printf("2, ");
      else printf("1, ");
    else printf("0, ");
    printf("depth = %d, ",free);
    printf("height = %d, ",height(i)-1); 
    if(ST2[i][1]==-1)printf("root"); 
    else{
      if(ST[i][0]==-1&&ST[i][1]==-1)printf("leaf");
      else printf("internal node");
    }
    printf("\n");
  }
  return 0;
}
int height(int killme){
  int baby;
  if(killme==-1)return 0;
  baby=height(ST[killme][0]);
  killme=height(ST[killme][1]);
  baby=killme>baby?killme:baby;
  return baby+1;
}
