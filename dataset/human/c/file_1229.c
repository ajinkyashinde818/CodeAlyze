// https://atcoder.jp/contests/abc082/tasks/abc082_b
// B - Two Anagrams
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

// 文字列の比較
int comp_s(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
        i++;
    }
    return 0;
}

// charバブルソート
void sort_c(char a[], int num) {
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

// 逆ソート
void sort_c_r(char a[], int num) {
    int i, j, b;
    for (i = 0; i < num-1; i++) {
        for (j = 0; j < num-i-1; j++) {
            if (a[j] < a[j+1]) {
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }
    }
}

int strlen_(char a[]) {
    int i = 0;
    while(a[i] != '\0') {
        i++;
    }
    return i;
}

int main(void) {
    char s[101];
    char t[101];
    int tn, sn;
    scanf("%s", s);
    scanf("%s", t);
    sn = strlen_(s);
    tn = strlen_(t);

    sort_c(s, sn);
    sort_c_r(t, tn);

    if (comp_s(s, t) < 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
