#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

}

void bubbleSortR(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

}

int main(void)
{
    char s[101], t[101];
    scanf("%s%s", s, t);

    int sl = strlen(s), tl = strlen(t);
    bubbleSort(s, sl);
    bubbleSortR(t, tl);

    int i;
    int f = 1;

    if (sl < tl) {
        for (i = 0; i < sl; i++) {
            if (s[i] != t[i]) {
                f = 0;
                break;
            }
        }
        if (f) {
            puts("Yes");
            return 0;
        }
    }
    int ll = sl < tl ? sl : tl;
    for (i = 0; i < ll; i++) {
        if (s[i] == t[i])
            continue;
        else if (s[i] < t[i]) {
            puts("Yes");
            return 0;
        }
        else {
            puts("No");
            return 0;
        }
    }
    puts("No");
    return 0;
}
