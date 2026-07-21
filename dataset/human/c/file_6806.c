#include <stdio.h>

void merge_sort(int array[], int right, int left) {
    int i, j, k, mid;
    int work[(left-right)+1];
    // printf("%d %d\n", right, left);
    if(right < left) {
        mid = (right + left) / 2;
        merge_sort(array, right, mid);
        merge_sort(array, mid+1, left);

        for(i=mid; i>=right; i--) {
            // printf("%d\n", i-right);
            work[i-right] = array[i];
        }
        for(j=mid+1; j<=left; j++) {
            // printf("%d\n", j-right);
            work[j-right] = array[left-(j-(mid+1))];
        }
        i = right;
        j = left;
        for(k=right; k<=left; k++) {
            if(work[i-right]>work[j-right]) array[k] = work[(i++)-right];
            else array[k] = work[(j--)-right];
        }
    }
}

void print_all(int array[], int array_size) {
    int i;
    for(i=0; i<array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    int a[3*N], i;
    for(i=0; i<3*N; i++) {
        scanf("%d", &a[i]);
    }

    // printf("before sort:\n");
    // print_all(a, 3*N);

    merge_sort(a, 0, 3*N-1);

    // printf("after sort:\n");
    // print_all(a, 3*N);

    long int sum=0;
    for(i=0; i<2*N; i++) {
        if(i%2) sum += a[i];
    }

    printf("%ld\n", sum);

    return 0;

}
