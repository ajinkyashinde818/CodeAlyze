#include <stdio.h>
int main()
{
    long long int r[200001]={0}, i, j, n, max=-1000000000, c, prev=1000000001;
    scanf("%lld", &n);
    for(i = 0; i < n; i++){
        scanf("%lld", &r[i]);
    }
    for(i = 0; i < n; i++){
        while(i < n){
            if(prev <= r[i]){
                i++;
            } else {
                break;
            }
        }
        for(j = i + 1; j < n; j++){
            c = r[j] - r[i];
            if(c > max){
                max = c;
            }
            prev = r[i];
        }
    }
    printf("%lld\n", max);
    return 0;
}
