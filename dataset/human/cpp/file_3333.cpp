#include <iostream>
#include <climits>
using namespace std;
//C - GCD on Blackboard
int main(void){
    int n,a[100000];
    std::cin >> n;
    int s=0,min=INT_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i]<=0)s++;
        if(abs(a[i])<min)min=abs(a[i]);
    }
    long long ans=0;
    for (int i = 0; i < n; i++) {
        ans+=abs(a[i]);
    }    
    if(s%2==1){
        ans-=min*2;        
    }

    std::cout << ans << std::endl;
}
