#include <cstdio>
#include <utility>
using namespace std;

int main(){
    int c[3],n;
    scanf("%d%d%d%d",&c[0],&c[1],&c[2],&n);
    int a[6000];
    a[0] = 1;
    for(int k = 0;k <= 2;k++){
        for(int j = 0;j < n+1-c[k];j++){
            a[j+c[k]] += a[j];
        }
    }
    printf("%d",a[n]);

    return 0;
}
