#include<stdio.h>
int main(){
  int n,i,j,l,min,max,a[1000][1000];
  char d[1000][1000];
  while(scanf("%d",&n),n){
    for(i=0;i<n;i++){
      for(j=l=0;j<n;j++){
	scanf(" %c",&d[i][j]);
	if(d[i][j]=='.')a[i][j]=++l;
	if(d[i][j]=='*')a[i][j]=l=0;
      }
    }
    for(i=max=0;i<n;i++){
      for(j=l=0;j<n;j++){
	if(d[j][i]=='.')l++;
	if(d[j][i]=='*')l=0;
	min=a[j][i];
	if(min>l)min=l;
	if(j&&i&&min>a[j-1][i-1]+1)min=a[j-1][i-1]+1;//printf("%d ",min);
	a[j][i]=min;
	if(max<min)max=min;
      }//printf("\n");
    }
    printf("%d\n",max);
  }
  return 0;
}
