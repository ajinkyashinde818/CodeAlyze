#include<stdio.h>

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int *arr,int maxlen,int begin,int end){
	int i,j;
	
	if(begin < end){
		i = begin + 1;
		j = end;
		
		while(i < j){
			if(arr[i] > arr[begin]){
				swap(&arr[i],&arr[j]);
				j--;
			}else{
				i++;
			}
		}
		if(arr[i] >= arr[begin]){
			i--;
		}
		swap(&arr[begin],&arr[i]);
		QuickSort(arr,maxlen,begin,i);
		QuickSort(arr,maxlen,j,end);
	}
} 

void ShellSort(int *arr,int size){
	int i,j,tmp,increment;
	
	for(increment = size/2;increment > 0;increment /= 2){
		for(i = increment;i < size;i++){
			tmp = arr[i];
			for(j = i - increment;j >= 0 && tmp < arr[j]; j -= increment)
				arr[j + increment] = arr[j];
			arr[j+increment] = tmp;
		}
	}
}

int main(){
	int k,n;
	scanf("%d %d",&k,&n);
	int a[n],dis[n],i;
	int max = 0;
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	dis[0] = a[0] + k - a[n-1];
	int sum = dis[0];
	for(i = 1;i < n;i++){
		dis[i] = a[i] - a[i-1];	
		if(dis[i] >= max)
			max = dis[i];
		sum += dis[i];
	}
	

	if(dis[0] > max)
		max = dis[0];
	//排序 找出其中最小的n-1个边 加起来
	//QuickSort(dis,n,0,n-1);
	//ShellSort(dis,n);
		
	printf("%d",sum-max);
	
	
	return 0;
	 
}
