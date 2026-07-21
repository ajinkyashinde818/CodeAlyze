#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
#define ll long long

int binS_first(int *a, int low, int high, int x);

int cmp(const void *x, const void *y) {
  const int *a = (const int *)x;
  const int *b = (const int *)y;
  if (a[0] == b[0])
    return a[1] - b[1];
  else
    return a[0] - b[0];
}

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    int service[m][2];
    for(i=0;i<m;i++) {
        scanf("%d %d",&service[i][0],&service[i][1]);
    }
    qsort(service, m, sizeof(service[0]), cmp);
    int a[m],b[m];
    for(i=0;i<m;i++) {
        a[i]=service[i][0];
        b[i]=service[i][1];
    }
    for(i=0;i<m;i++){
        if(a[i]!=1) break;
        int find=binS_first(a, 0, m-1, b[i]);
        if(find==-1) continue;
        while(find<m && a[find]==b[i]){
            if(b[find]==n){
                printf("POSSIBLE\n");
                return 0;
            }
            find++;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}

int binS_first(int *a, int low, int high, int x)  {
    if(NULL == a || low > high)return -1;
    int mid;
    while(low<high)//<
    {
        mid=low+((high-low)>>1);
        if(a[mid]<x)// <x
            low=mid+1;
        else // >=x
            high=mid;
    }
    if(a[low] == x)
        return low;
    return -1;
}
