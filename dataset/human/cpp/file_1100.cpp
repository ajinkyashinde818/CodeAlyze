#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>	
#include <utility>
#include <cinttypes>
using namespace std;
int main(){
    int r,g,b,n;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    int counter = 0;
    for (int i=0;i<=n/r;i++){
        for (int j=0;j<=(n-r*i)/g;j++){
            if ((n-r*i-g*j)%b == 0){
                counter ++;
            }
        }
    }
    printf("%d\n",counter);
}
