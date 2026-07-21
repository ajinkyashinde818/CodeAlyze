#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    long long int ans=0,counter=0;
    std::cin >> n;
    long long int a[n];
    for (i=0;i<n;i++){
        std::cin >>a[i];
        if (a[i]<0){
            counter++;
            a[i]= -a[i];
        }
    }
    if (counter%2==0){
        for (i=0;i<n;i++)
        ans+=a[i];
    }
    if(counter%2==1){
        sort(a, a+n);
        for (i=1;i<n;i++){
            ans+=a[i];
        }
        ans-=a[0];
    }
    std::cout <<ans << std::endl;
}
