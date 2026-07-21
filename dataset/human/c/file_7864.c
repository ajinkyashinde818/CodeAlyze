#include<stdio.h>
int main(){
  int f[1000]={2,3};
  int n,m,i,j,c,r[1000],t;
  for(i=2;i<1000;i++)f[i]=(f[i-1]+f[i-2])%1001;
  while(scanf("%d %d",&n,&m)!=EOF){
    for(i=0;i<n;i++){
      r[i]=i;
      for(j=i;j;j--){
	if(f[r[j-1]]>f[r[j]]){
	  t=r[j-1];
	  r[j-1]=r[j];
	  r[j]=t;
	}
      }
    }
    for(i=c=1;i<n;i++){//printf("%d\n",f[r[i]]);
      if(f[r[i]]-f[r[i-1]]>=m)c++;
    }
    printf("%d\n",c);
  }
  return 0;
}
