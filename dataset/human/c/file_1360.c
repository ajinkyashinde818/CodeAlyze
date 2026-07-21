#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
    return n;
}

unsigned long  gcd(unsigned long x, unsigned long y)
{
        if (y == 0) {
                return x;
        } else {
                return gcd(y, x % y);
        }
}

int boat_from_1[200005] = {0};
int boat_to_n[200005] = {0};


int main(void){
    int n, m;
    int i;
    int j = 0;
    int k = 0;
    int a,b;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        if (a == 1){
            boat_from_1[j] = b;
            j++;
        }
        if (b == n){
            boat_to_n[k] = a;
            k++;
        }
    }
    qsort(boat_from_1, j, sizeof(int), ascending_compare);
    qsort(boat_to_n, k, sizeof(int), ascending_compare);

    for (i = 0; i < j; i++){
        if (bsearch(&boat_from_1[i], boat_to_n, k, sizeof(int), ascending_compare) != NULL){
            printf("POSSIBLE\n");
            return 0;
        }
    }

    printf("IMPOSSIBLE\n");

    return 0;

}
