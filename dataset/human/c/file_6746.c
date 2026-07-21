#include<stdio.h>

int main(){
  int n,m;
  int i,j;

  scanf("%d",&n);
  scanf("%d",&m);
  while((n!=0)&&(m!=0)){
    int a[m],b[m];
    int fc[n+1];
    int f[n+1];
    int cnt;

    for(i=0;i<m;i++){
      scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<n+1;i++){
      fc[i]=0;
      f[i]=0;
    }

    j=0;

    for(i=0;i<m;i++){
      if(a[i]==1){
	fc[b[i]]=1;
	f[j]=b[i];
	j++;
      }
    }

    for(i=0;i<j;i++){
      int k;
      for(k=0;k<m;k++){
	if(a[k]==f[i]){
	  fc[b[k]]=1;
	}
	if((b[k]==f[i])&&(a[k]!=1)){
	  fc[a[k]]=1;
	}
      }
    }

    cnt=0;
    for(i=0;i<n+1;i++){
      if(fc[i]==1){
	cnt++;
      }
    }

    printf("%d\n",cnt);

    scanf("%d",&n);
    scanf("%d",&m);
  }

  return 0;
}
