#include<stdio.h>
#include<string.h>
int a[10001];
int b[10001];
int temp[10001];
int memo[501];
main(){
  int n,m;
  int i,j;
  int tamp;
  int k;
  int co;

  while(1){
    scanf("%d",&n);
    scanf("%d",&m);
    if(n==0 && m==0) break;

    for(i=0;i<m;i++)
      scanf("%d %d",&a[i],&b[i]);

    memset(memo,0,sizeof(memo));
    co=0;
    j=0;
    for(i=0;i<m;i++){
      if(a[i]==1){
	temp[j]=b[i];
	memo[a[i]]=1;
	memo[b[i]]=1;
	a[i]=0;
	b[i]=0;
	co++;
	j++;
      }
      else if(b[i]==1){
	temp[j]=a[i];
	memo[a[i]]=1;
	memo[b[i]]=1;
	a[i]=0;
	b[i]=0;
	co++;
	j++;
      }
    }

    tamp=j;
         
    for(j=0;j<tamp;j++){
      for(i=0;i<m;i++){
	if(a[i]==temp[j]){
	  if(memo[b[i]]==1){
	    a[i]=0;
	    b[i]=0;
	  }
	  else{
	    memo[b[i]]=1;
	    memo[a[i]]=1;
	    a[i]=0;
	    b[i]=0;
	    co++;
	  }
	}
	else if(b[i]==temp[j]){
	  if(memo[a[i]]==1){
	    a[i]=0;
	    b[i]=0;
	  }
	  else{
	    memo[b[i]]=1;
	      memo[a[i]]=1;
	      a[i]=0;
	      b[i]=0;
	      co++;
	  }
	}
      }
    }

    printf("%d\n",co);
  }
  return 0;
}
