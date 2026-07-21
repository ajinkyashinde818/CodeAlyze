// https://atcoder.jp/contests/agc012/tasks/agc012_a
// A - AtCoder Group Contest
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 標準入力から改行かスペースまで読み取り、数字として返す
int get_num() {
    // 10文字+区切り文字までしか受け付けられない
    char s[11];
    int i, n;
    // scanf()の直後は改行が入力に残っているので、
    // 最初の改行は読み飛ばす
    do {
        s[0] = getchar();
    } while (s[0] == '\0' || s[0] == '\n');
    for (i = 1; i < sizeof(s); i++) {
        s[i] = getchar();
        if (s[i] == ' ' || s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }
    sscanf(s, "%d", &n);
    return n;
}


// intバブルソート
void sort(int a[], int num) {
    int i, j, b;
    for (i = 0; i < num-1; i++) {
        for (j = 0; j < num-i-1; j++) {
            if (a[j] > a[j+1]) {
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }
    }
}

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void) {
    int a[300000];
    int n;
    long sum = 0;
    n = get_num();
    //n = 100000;

    for (int i = 0; i < 3 * n; i++) {
        //a[i] = 1000000000;
        a[i] = get_num();
    }

//    sort_q(a, n*3);
    qsort(a, n*3, sizeof(int), compare_int);
    
    for (int i = 0; i < n; i++) {
        sum += a[n*3-1 - (i*2+1)];
    }
    
    printf("%ld", sum);
    
    return 0;
}
