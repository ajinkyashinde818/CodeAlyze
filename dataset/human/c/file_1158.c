#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


int main(void){
    char *s = (char*)malloc(101 * sizeof(char));
    char *t = (char*)malloc(101 * sizeof(char));
    scanf("%s", s);
    scanf("%s", t);


    int S = strlen(s);
    int T = strlen(t);
    int i, j;
    for(i=0; i<S-1; i++) {
        for(j=S-1; j>= i+1; j--) {
            if(s[j] < s[j-1]) {
                char temp;
                temp = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp;
            }
        }
    }
    for(i=0; i<T-1; i++) {
        for(j=T-1; j>= i+1; j--) {
            if(t[j] > t[j-1]) {
                char temp;
                temp = t[j];
                t[j] = t[j - 1];
                t[j - 1] = temp;
            }
        }
    }

    if(strcmp(s, t) < 0) {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
  free(s);
  free(t);
  return 0;
}
