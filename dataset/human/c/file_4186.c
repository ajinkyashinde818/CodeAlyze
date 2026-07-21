#include <stdio.h>

#define MAX 100

int main(){

    int a;
    int spls_a;
    int ary_a[MAX];
    int cnt_a = 0;
    int max_a;

    int b;
    int spls_b;
    int ary_b[MAX];
    int cnt_b = 0;
    int max_b;

    int i;
    int j;

    int k;
    int ary_k[MAX];
    int cnt_k = 1;

    scanf("%d %d %d", &a, &b, &k);

    for(i=1 ; i<=MAX ; i++){

        spls_a = a%i;
        spls_b = b%i;

        if(spls_a==0){
            ary_a[cnt_a] = i;
            cnt_a++;
        }
        if(spls_b==0){
            ary_b[cnt_b] = i;
            cnt_b++;
        }
    }

    max_a = cnt_a;
    max_b = cnt_b;

    for(i=0 ; i<max_a ; i++){
        for(j=0 ; j<max_b ; j++){
            if(ary_a[i]==ary_b[j]){
                ary_k[cnt_k] = ary_a[i];
                cnt_k++;
            }
        }
    }

    printf("%d", ary_k[cnt_k-k]);

}
