#include<stdio.h>
int main(){
  int n,m,x,i,k,d[2][200020],r[2],w[2][200020]={};
  char s[2][200020]={};
  scanf("%d %d %d %s",&n,&m,&x,s[0]);
  for(k=0;k<2;k++){
    for(i=r[k]=0;i<n;i++){
      if(d[k][i]==0){
	if(s[k][i]=='o'){
	  w[k][r[k]++]=i;
	  d[k][i+1]=x;
	}
      }
      else d[k][i+1]=d[k][i]-1;
    }
    for(i=0;i<n;i++)s[1][i]=s[0][n-i-1];
    //printf("%s\n",s[1]);
  }
  //for(i=0;i<r[0];i++)printf("%d ",  w[0][i    ]  );printf("\n");
  //for(i=0;i<r[1];i++)printf("%d ",n-w[1][m-i-1]-1);printf("\n");
  //printf("%d %d %d\n",
  if(r[0]==r[1]&&r[0]==m){
    for(i=0;i<m;i++){
      if(w[0][i]==n-w[1][m-i-1]-1)printf("%d\n",w[0][i]+1);
    }
  }
  return 0;
}
