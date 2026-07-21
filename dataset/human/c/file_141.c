#include <stdio.h>

int min3(int x, int y, int z){
    int min = x;
    if (y < min) min = y;
    if (z < min) min = z;
    return min;
}

int main(){
    int r,g,b,n;
    long ans = 0;

    scanf("%d %d %d %d",&r,&g,&b,&n);

    int lr = n/r+1;
    int lg = n/g+1;

    for (int i =lr; i >= 0; i--){
        if(i*r>n){
            continue;
        }else{
            for (int j =lg; j >= 0; j--){
                if(i*r+j*g>n){
                    continue;
                } else {
                    if((n - (i * r + j * g)) % b == 0){
                        ans++;
                    }

                }
            }
        }
    }
    printf("%ld\n",ans);

    return 0;
}
