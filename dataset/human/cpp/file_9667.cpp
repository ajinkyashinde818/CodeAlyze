#include<cstdio>
using namespace std;
int main(){
  int n,m,flag;
  char a[51][51],b[51][51];
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)
    scanf("%s",a[i]);
  for(int i=0;i<m;i++)
    scanf("%s",b[i]);
  for(int i=0;i<n-m+1;i++)
    for(int j=0;j<n-m+1;j++){
      flag=1;
      for(int k=0;k<m;k++)
        for(int l=0;l<m;l++)
          if(a[i+k][j+l]!=b[k][l])
            flag=0;
      if(flag){
        printf("Yes\n");
        return 0;
      }
    }
  printf("No\n");
}
