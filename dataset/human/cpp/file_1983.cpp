#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    int cnt=0;
    long int min=1000000000;
    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        if(tmp<0) cnt++;
        a[i] = abs(tmp);
        if(abs(tmp)<min) min = abs(tmp);
    }
    long long int sum=0;
    for(int i=0;i<N;i++){
        sum = sum + a[i];
    }
    if(cnt%2==0) cout << sum << endl;
    else cout << sum - 2*min << endl;
}
