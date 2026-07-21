#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
  int n,s[500][500],f[100010]={},cnt=0,p=1;
  scanf("%d",&n);
  for(int i=1;i*(i-1)<=2*n;i++){
    if(i*(i-1)==2*n){
      printf("Yes\n");
      printf("%d\n",i);
      for(int j=0;j<i;j++){
        cnt=0;
        for(int k=0;k<j;k++){
          for(int l=0;l<i-1;l++){
            if(f[s[k][l]]==1){
              s[j][cnt]=s[k][l];
              f[s[k][l]]++;
              cnt++;
              break;
            }
          }
        }
        for(int k=cnt;k<i-1;k++){
          while(f[p]!=0)
            p++;
          s[j][k]=p;
          f[p]++;
        }
        printf("%d ",i-1);
        for(int k=0;k<i-1;k++)
          printf("%d ",s[j][k]);
        printf("\n");
      }
      return 0;
    }
  }
  printf("No\n");
}
