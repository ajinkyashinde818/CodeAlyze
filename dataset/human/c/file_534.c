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


int card[200005];



int main(void){
    int n;
    int i;
    long long snuke = 0;
    long long raccoon = 0;
    long long total = 0;
    long long min = 200000000000010;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &card[i]);
        total += card[i];
    }

    for (i = 0; i < n-1; i++){
        snuke += card[i];
        raccoon = total - snuke;
        min = min>llabs(raccoon - snuke)?llabs(raccoon - snuke):min;
    }

    printf("%lld\n", min);

    return 0;

}
