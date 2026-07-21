#include<stdio.h>
void swap(int x[],int i,int j){
    int tmp;
    
    tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
}

void qsort(int x[],int left,int right){
    int i,j;
    int pivot;
    
    i = left;
    j = right;
    pivot = x[(left + right) / 2];
    
    while(1){
        while(x[i] < pivot) i++;
        while(x[j] > pivot) j--;
        if(i >= j) break;
        swap(x,i,j);
        i++;
        j--;
    }
    
    if(left < i-1) qsort(x,left,i-1);
    if(right > j+1) qsort(x,j+1,right);
}
int main(){
    int i,k,n;
    int a[200000];
    int distance[200000];
    int ans = 0;
    
    scanf("%d %d",&k,&n);
    for(i = 0; i < n; i++) scanf("%d",&a[i]);
    
    for(i = 0; i < n-1; i++){
        distance[i] = (a[i+1]-a[i]);
    }
    distance[n-1] = k-a[i]+a[0];
    qsort(distance,0,n-1);
//    for(i = 0; i < n; i++) printf("%d\n",distance[i]);
    
    
//    for(i = 0; i < n; i++) printf("%d\n",distance[i]);
    
    for(i = 0; i < n-1; i++){
        ans += distance[i];
    }
    printf("%d\n",ans);
    return 0;
}
