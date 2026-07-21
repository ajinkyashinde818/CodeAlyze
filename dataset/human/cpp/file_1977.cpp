#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    double a[100010];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    int count = 0;
    double sum = 0;
    for(int i=0;i<n;++i){
        if(a[i] < 0){
            ++count;
            a[i] = -a[i];
        }
        sum += a[i];
        //cout<<sum<<" ";
    }
    sort(a, a + n); 
    if(count%2 == 1)sum -= a[0]*2;

    //cout<<endl;
    cout<<fixed<<setprecision(0)<<sum;
}
