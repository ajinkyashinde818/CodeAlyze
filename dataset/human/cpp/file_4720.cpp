#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void){
    int n = 0, r = 0; 

    scanf("%d%d", &n, &r);

    if(n < 10){
        printf("%d\n", r + 100*(10-n));

    }else{
        printf("%d\n", r);
    }

    return 0;

}
