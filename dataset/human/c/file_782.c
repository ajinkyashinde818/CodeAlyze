#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char str[100];

int max(int a,int b){
    if(a>b)return a;
    return b;
}

int min(int a,int b){
    if(a<b)return a;
    return b;
}

void getInput(char *pstr)
{
    fgets(pstr, sizeof(str), stdin);
}

int main() {
    char *pstr = &str[0];
    int D, G = 0;
    int p[10], c[10];
    
    /* 標準入力の処理 */
    getInput(pstr);
    D = atoi(strtok(pstr, " "));
    G = atoi(strtok(NULL, " "));
    for (int i = 0; i < D; i++)
    {
        getInput(pstr);
        p[i] = atoi(strtok(pstr, " "));
        c[i] = atoi(strtok(NULL, " "));
    }
    
    int result = 100000000;
    /* 計算 */
    for(int i = 0; i < pow(2, D); i++){
        int bit = i;
        int currentValue = 0;
        int count = 0;
        int maxNotCmp = -1;
        for(int j = 0; j < D; j++){
            if ((bit >> j) % 2 == 1) {
                currentValue += 100 * (j + 1) * p[j] + c[j];
                count += p[j];
            } else {
                maxNotCmp = max(maxNotCmp, j);
            }
        }
        if(currentValue < G){
            int need = G - currentValue;
            if (need > 100 * (maxNotCmp + 1) * (p[maxNotCmp] - 1)) {
                continue;
            }
            count += (need + 100 * (maxNotCmp + 1) - 1) / (100 * (maxNotCmp + 1));
        }
        result = min(result, count);
    }
    /* 結果の出力 */
    printf("%d\n", result);
    return 0;
}
