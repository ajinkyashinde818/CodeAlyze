#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}


int main(){
  int n = 0;
  int m = 0;
  int a[200000] = {};
  int b[200000] = {};
  int go[200000] = {};
  int cnt = 0;
  int merged[400000]= {};
  int i = 0;
  int success = 0;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d",&a[i],&b[i]);
  }
  
  for(i=0;i<m;i++){
    if(a[i] == 1){
      go[cnt] = b[i];
      cnt++;
    }
  }
  for(i=0;i<m;i++){
    if(b[i] == n){
      go[cnt] = a[i];
      cnt++;
    }
  }
  qsort(go,cnt,sizeof(int),cmp);
  for(i=1;i<cnt;i++){
    if(go[i-1] == go[i]){
      success = 1;
      break;
    }
  }
  
  if(success){
    printf("POSSIBLE");
  }else{
    printf("IMPOSSIBLE");
  }
  return 0;
}
