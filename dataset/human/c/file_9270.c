#include <stdio.h>

int main(int argc, char* argv[]) {
    int num=0, least=0, passed=0;
    scanf("%d %d", &num, &least);
    for(int i=0; i < num; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);
        if(tmp >= least) passed += 1;
    }
    printf("%d\n", passed);
    return 0;
}
