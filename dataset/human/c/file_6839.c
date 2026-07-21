#include<stdio.h>

int temp[300001];

void MergeSort(int x[],int left,int right);

int main(void){
  int N,i,j,sizeof_a;
  int a[300001];
  long long sum=0;
  scanf("%d",&N);
  sizeof_a=3*N;
  for(i=0;i<sizeof_a;i++) scanf("%d",&a[i]);
  MergeSort(a,0,sizeof_a-1);
  //for(i=0;i<sizeof_a;i++) printf("%d",a[i]);
  //putchar('\n');
  for(i=sizeof_a-2,j=0;j<N;i-=2,j++){
    sum+=a[i];
  }
  printf("%lld\n",sum);
  return 0;
}

void MergeSort(int x[],int left,int right){
  int mid,i,j,k;
  if(left >= right) return;
  mid = (left+right)/2;
  MergeSort(x,left,mid);
  MergeSort(x,mid+1,right);

  for(i=left;i<=mid;i++) temp[i] = x[i];
  for(i=mid+1,j=right;i<=right;i++,j--) temp[i]=x[j];

  i=left;
  j=right;

  for(k=left;k<=right;k++){
    if(temp[i] <= temp[j]) x[k] = temp[i++];
    else x[k] = temp[j--];
  }
}
