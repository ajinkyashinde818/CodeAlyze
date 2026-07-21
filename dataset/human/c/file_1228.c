#include <stdio.h>
#include <string.h>

void MaxSort(char *s);
void MinSort(char *s);

int main(){
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);

    MinSort(s);
    MaxSort(t);

    printf((strcmp(s, t) < 0) ? "Yes\n" : "No\n");
    return 0;
}

void MaxSort(char *s){
    char tmp;
    int maxnum, n = strlen(s);
    for(int i = 0; i < n; i++){
        maxnum = i;
        for(int j = i; j < n; j++){
            if(s[j] > s[maxnum]){
                maxnum = j;
            }
        }
        tmp = s[i];
        s[i] = s[maxnum];
        s[maxnum] = tmp;
    }
}

void MinSort(char *s){
    char tmp;
    int minnum, n = strlen(s);
    for(int i = 0; i < n; i++){
        minnum = i;
        for(int j = i; j < n; j++){
            if(s[j] < s[minnum]){
                minnum = j;
            }
        }
        tmp = s[i];
        s[i] = s[minnum];
        s[minnum] = tmp;
    }
}
