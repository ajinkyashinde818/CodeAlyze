#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,r;
    while (scanf("%d %d",&n,&r)!=EOF) {
        if (n>=10)
            printf("%d\n",r);
        else {
            printf("%d\n",r+100*(10-n));
        }
    }
    return 0;
}
