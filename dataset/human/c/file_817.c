#include<stdio.h>
#include<math.h>

int main(){
    int count;
    unsigned long int d, g;
    scanf("%lu%lu", &d, &g);
    g = g/100;
    unsigned long int p[d+1], c[d+1], a[d+1], f[d+1];
    for(int i=1; i<=d; i++){
        scanf("%lu%lu", &p[i], &c[i]);
        c[i] = c[i]/100;
        a[i] = i*p[i] + c[i];
        count += p[i];
    }
    int x = pow(2, d) - 1;
    while(x >= 0){
        int y = x;
        unsigned long int buf = 0, sum = 0;
        x--;
        for(int i=1; i<=d; i++){
            if(y%2 == 1){
                sum += a[i];
                buf += p[i];
            }
            f[i] = y%2;
            y = y/2;
        }
        if(count > buf && g <= sum){
            count = buf;
            continue;
        }
        int id;
        for(int i=d; i>=1; i--){
            if(f[i] == 0){
                buf += (g-sum+i-1)/i;
                sum += i*(p[i]-1);
                break;
            }
        }
        if(count > buf && g <= sum){
            count = buf;
        }
    }
    printf("%lu", count);

    return 0;
}
