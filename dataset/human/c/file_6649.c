#include <stdio.h>
#include <limits.h>
int FindMaxCrossingSubarray(int A[], int low, int mid, int high);
int FindMaximumSubarray(int A[], int low, int high);
int main(){
  int n;
  int i, j;
  scanf("%d", &n);
  int N[n];
  int R[n-1];
  int max=INT_MIN;
  int tmp;
  for(i=0; i<n; ++i){
	scanf("%d", &N[i]);
  }
  for(i=0; i<(n-1); ++i){
	R[i]=N[i+1]-N[i];
  }
  //sort
 int min=N[0];
  for(i=1; i<n; ++i){
	tmp=N[i]-min;
	if(tmp>max)
	  max=tmp;
	if(min>N[i])
	  min=N[i];
  }
  //

  /* for(i=0; i<(n-1); ++i){ */
  /* 	printf("%d ", R[i]); */
  /* } */
  /* printf("\n"); */
  printf("%d\n", max);
  return 0;
}

int FindMaxCrossingSubarray(int A[], int low, int mid, int high){
  int sum=0;
  int leftsum=INT_MIN, rightsum=INT_MIN;
  int i;
  for(i=mid; i>=low; --i){
	sum+=A[i];
	if(sum>leftsum)
	  leftsum=sum;
  }
  sum=0;
  for(i=(mid+1); i<=high; ++i){
	sum+=A[i];
	if(sum>rightsum)
	  rightsum=sum;
  }
  return (leftsum+rightsum);
}
int FindMaximumSubarray(int A[], int low, int high){
  if(low==high)  
	return A[low];
  else{
	int mid;
	mid=(low+high)/2;
	int leftsum, rightsum, crosssum;
	leftsum=FindMaximumSubarray(A, low, mid);
	rightsum=FindMaximumSubarray(A, mid+1, high);
	crosssum=FindMaxCrossingSubarray(A, low, mid, high);
	if((leftsum>=rightsum)&&(leftsum>=crosssum))
	  return leftsum;
	else if((rightsum>=leftsum)&&(rightsum>=crosssum))
	  return rightsum;
	else
	  return crosssum;
  }
}
