#include<stdio.h>
int main(){
	int n,m,a,b,i,a1[220000],b1[220000];
  	scanf("%d%d",&n,&m);
  	for(i=0;i<m;i++){
      scanf("%d%d",&a,&b);
      if(a==1)b1[b]++;
      if(b==n)a1[a]++;
	}
	for(i=2;i<=n;i++){
        if(a1[i]>0&&b1[i]>0){
          puts("POSSIBLE");
          return 0;
        }
    }
  puts("IMPOSSIBLE");
  return 0;
}
