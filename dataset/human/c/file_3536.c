#include<stdio.h>

int main(){
  int n, p[100], i, j, tmp, large, ans;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &p[i]);
  }

  for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if(p[i]<p[j]){
	tmp=p[i];
	p[i]=p[j];
	p[j]=tmp;
      }
    }
  }

  for(i=1; i<=n; i++){
    large=0;
    for(j=0; j<n; j++){
      if(p[j]>=i){
	large++;
      }else{
	break;
      }
    }
    if(large>=i){
      ans=i;
    }else if(large<i){
      break;
    }
  }
    

  printf("%d\n", ans);
  
  return 0;
}
