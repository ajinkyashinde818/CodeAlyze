#include<bits/stdc++.h>
using namespace std;

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
  int i,j,k,N,a[3],b[3],cnt=0;
  scanf("%d",&a[0]);
  scanf("%d",&a[1]);
  scanf("%d",&a[2]);
  qsort(a,3,sizeof(int),intsort);
  scanf("%d",&N);
  b[0]=N/a[0];
  N+=a[0];
  for(i=0;i<=b[0];i++){
    N-=a[0];
    b[1]=N/a[1];
    for(j=0;j<=b[1];j++){
      if((N-a[1]*j)%a[2]==0)cnt++;
    }
  }
  printf("%d",cnt);
  return 0;
}
