#include <stdio.h>

int main(){
  int n,k,c,p[200005],i,j,m;
  char s[200005];
  scanf("%d",&n);
  scanf("%d",&k);
  scanf("%d",&c);
  scanf("%s",&s);
  if(c==0){
    m=0;
    for(i=0;i<n;i++){
      if(s[i]=='o') m++;
    }
    if(k==m){
      for(i=0;i<n;i++){
        if(s[i]=='o'){
          printf("%d\n",i+1);
        }
      }
    }
  }else{
    j=k-1;
    for(i=n-1;j>=0;i--){
      if(s[i]=='o'){
        p[j]=i;
        j--;
        i-=c;
      }
    }
    j=0;
    for(i=0;j<k;i++){
      if(s[i]=='o'){
        if(p[j]==i){
          printf("%d\n",i+1);
        }
        j++;
        i+=c;
      }
    }
  }
  return(0);
}
