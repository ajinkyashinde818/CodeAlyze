#include <stdio.h>

int find_min(int a[], int start, int end)
{
    int min = a[start];
    for(int i=start; i<=end; i++){
        if(a[i] <= min)
            min = a[i];
    }
    return min;
}

int find_max(int a[], int start, int end)
{
    int max = a[start];
    for(int i=start; i<=end; i++){
        if(a[i] >= max)
            max = a[i];
    }
    return max;
}

int max_of(int a, int b){
    return (a>=b) ? a:b;
}

int min_of(int a, int b){
    return (a<=b) ? a:b;
}

int find_max_diff(int a[], int start, int end, int left_min[], int right_max[])
{
    int i,j;
    int max = -1000000000;
    if((end - start) == 2){
        max = max_of(max_of(a[end-1]-a[end-2], a[end]-a[end-2]), a[end]-a[end-1]);
        left_min[end] = find_min(a, start, end);
        right_max[end] = find_max(a, start, end);
        return max;
    }
    else if((end-start)==1){
        if((a[end]-a[start]) <= 0){
            left_min[end] = a[end]; 
            right_max[end] = a[start];
        }
        else{
            left_min[end] = a[start]; 
            right_max[end] = a[end];
        }
        return a[end] - a[start];
    }
    else{
        int mid = (start+end)/2;
        int left_diff = find_max_diff(a, start, mid, left_min, right_max);
        int right_diff = find_max_diff(a, mid+1, end, left_min, right_max);
        int all_diff = right_max[end] - left_min[mid];
        right_max[end] = max_of(right_max[mid], right_max[end]);
        left_min[end] = min_of(left_min[mid], left_min[end]);
        return max_of(max_of(left_diff, right_diff), all_diff);
    }
}

int main(){
    
    int data_num, arr[250000];
    scanf("%d", &data_num);
    
    for(int i=0; i<data_num; i++){
        scanf("%d", &arr[i]);
    }

    int left_min[250000], right_max[250000];
    int ans = find_max_diff(arr, 0, data_num-1, left_min, right_max);
    printf("%d\n", ans);
}
