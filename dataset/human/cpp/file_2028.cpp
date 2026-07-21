#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

int main(void){
    
    int n,i,odd=0;
    ll tmp,a[100000],sum=0,min=1000000001;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            tmp=a[i]*-1;
            odd++;
        }
        else{
            tmp=a[i];
        }
        sum+=tmp;
        if(min>tmp){
            min=tmp;
        }
    }
    if(odd%2==1)cout<<sum-min-min<<endl;
    else cout<<sum<<endl;

	return 0;
}
