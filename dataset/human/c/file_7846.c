#include<stdio.h>
int f[1010][1010],y[1000010],x[1000010],l[1010][1010];
int main(){
  int Y[]={1,0,-1,0};
  int X[]={0,1,0,-1};
  int n,m,ny,nx,gy[11],gx[11],i,j,k,a=0,t,r;
  char s[1010][1010]={};
  scanf("%d %d %d",&n,&m,&k);
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf(" %c",&s[i][j]);
      if(s[i][j]=='S')s[i][j]='0';
      if('0'<=s[i][j]&&s[i][j]<='9')s[gy[s[i][j]-'0']=i][gx[s[i][j]-'0']=j]='.';
    }
  }
  //for(i=0;i<=k;i++)printf("%d %d\n",gy[i],gx[i]);
  for(i=0;i<k;i++){
    f[y[t=0]=gy[i]][x[  0]=gx[i]]=i+1;
    l[y[0]][x[0]]=0;
    for(r=1;r-t;t++){
      for(j=0;j<4;j++){
	ny=y[t]+Y[j];
	nx=x[t]+X[j];//printf("%d\n",f[ny][nx]);
	if(s[ny][nx]-'.'||f[ny][nx]==i+1)continue;
	f[y[r]=ny][x[r]=nx]=i+1;
	l[ny][nx]=l[y[t]][x[t]]+1;
	r++;
      }
    }//printf("%d\n",r);
    /*for(j=0;j<n;j++){
      for(t=0;t<m;t++)printf("%d ",l[j+1][t+1]);printf("\n");
      }//*/
    a+=l[gy[i+1]][gx[i+1]];
  }
  printf("%d\n",a);
  return 0;
}
