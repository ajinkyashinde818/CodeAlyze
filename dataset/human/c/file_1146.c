#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(char a[], char b[]){
    int i=0;
    while(a[i] != '\0'){
        if(a[i] != b[i]){
            return a[i] - b[i];
        }
        i++;
    }
    return 0;
}
void sort1(char x[], int n){
    int i, j;
    char y;
    for(i=n; i>1; i--){
        for(j=0; j<=i-2; j++){
            if(x[j] > x[j+1]){
                y = x[j];
                x[j] = x[j+1];
                x[j+1] = y;
            }
        }
    }
}
void sort2(char x[], int n){
    int i, j;
    char y;
    for(i=n; i>1; i--){
        for(j=0; j<=i-2; j++){
            if(x[j] < x[j+1]){
                y = x[j];
                x[j] = x[j+1];
                x[j+1] = y;
            }
        }
    }
}
int main(void){
    char s[101];
    char t[101];
    int i=0;
    int sl=0, tl=0;
    
    scanf("%s", s);
    scanf("%s", t);
    
    while(s[i] != '\0'){
        sl++;
        i++;
    }
    i = 0;
    while(t[i] != '\0'){
        tl++;
        i++;
    }
    
    sort1(s, sl);
    sort2(t, tl);
    
    //printf("%d\n", comp(s, t));
    
    if(comp(s, t) < 0 || (comp(s, t) == 0 && sl < tl)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    return 0;
}
