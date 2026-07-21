#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int max(int a,int b){
	if(a>b)return a;
	return b;
}

int min(int a,int b){
	if(a<b)return a;
	return b;
}

int compare_char(char *a,char *b){
	return strcmp(a,b);
}

int intsort(const void *a, const void *b){
	return *(int*)b - *(int*)a;
	/*qsort(a,aの配列数,sizeof(int),intsort);*/
}

int longsort(const void *a, const void *b){
	long *A=(long *)a;
	long *B=(long *)b;
	if(*A>*B) return -1;
	if(*A<*B) return 1;
	return 0;
}

int main(){
  int i,N,t=1;
  long min,cnt,now;
  scanf("%d",&N);
  scanf("%ld",&min);
  if(min<0)t=-1;
  min=labs(min);
  cnt=min;
  for(i=1;i<N;i++){
    scanf("%ld",&now);
    if (now<0){
      t*=-1;
    }
    now=labs(now);
    if(min>now)min=now;
    cnt+=now;
  }
  if(t==1){
    printf("%ld\n",cnt);
  }else{
    printf("%ld\n",cnt-min*2);
  }
  return 0;
}
