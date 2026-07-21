#include<stdio.h>
void swap (long long int *x,long long int *y) {
  long long int temp = *x;
  *x = *y;
  *y = temp;
}
int partition (long long int array[],long long int left,long long int right) {
  long long int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left;
  do {
    do { i++; } while (array[i] < array[pivot]);
    do { j--; } while (array[pivot] < array[j]);
    if (i < j) { swap(&array[i], &array[j]); }
  } while (i < j);
  swap(&array[pivot], &array[j]);
  return j;
}
void quick_sort (long long int array[],long long int left,long long int right) {
  long long int pivot;
  if (left < right) {
    pivot = partition(array, left, right);
    quick_sort(array, left, pivot-1);
    quick_sort(array, pivot+1, right);
  }
}

int main(){
  long long int n,ans = 0,i;
  scanf("%lld",&n);
  long long int a[3 * n];
  for(i = 0;i < 3 * n;i++){
    scanf("%lld",&a[i]);
  }
  quick_sort(a,0,3 * n - 1);
  for(i = n;i < 3 * n;i += 2){
    ans += a[i];
  }
  printf("%lld\n",ans);
  return 0;
}
