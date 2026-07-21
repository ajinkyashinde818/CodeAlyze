#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define rep(i, n) for(int i=0; i<(n); ++i)
#define max  200001

//qsort(str, n, sizeof(int), up_comp);
int up_comp(const void *a, const void *b){return *(int*)a - *(int*)b;}
int down_comp(const void *a, const void *b){return *(int*)b - *(int*)a;}
int int_sort( const void * a , const void * b ) {return strcmp(( char * )a , ( char * )b );}
int count_digit(int a){int i=0;while(a!=0){a=a/10;i++;}return i;}
int euclid( int a, int b ){int temp;if(a<b){temp=a;a=b;b=temp;}if(b<1)return -1;if(a%b==0) return b;return euclid(b,a%b);}

int main(void){
    
    int lens, lent;
    char s[max], t[max], tmp;
    
    scanf("%s%s", s, t);
    
    lens=strlen(s);
    lent=strlen(t);
    
    for (int i=0; i<lens; i++) {
        for (int j=i+1; j<lens; j++) {
            if (s[i]>s[j]) {
                tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    
    for (int i=0; i<lent; i++) {
        for (int j=i+1; j<lent; j++) {
            if (t[i]<t[j]) {
                tmp=t[i];
                t[i]=t[j];
                t[j]=tmp;
            }
        }
    }

    if (strcmp(s, t)<0) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
