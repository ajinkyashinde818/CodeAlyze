#include <iostream>
using namespace std;
int main(void){
    int n;
    long int a;
    scanf("%d\n",&n);
    long int sum=0; 
    long int min=1000000000;
    int cou=0;
    for(int i=0;i<n;i++){
        scanf("%ld",&a);
        if(a<0){sum-=a;cou++;}
        else sum+=a;
        if(abs(a)<min)min=abs(a);
    }
    if(cou%2==1)sum-=2*min;
    printf("%ld\n",sum);
    return 0;
}
