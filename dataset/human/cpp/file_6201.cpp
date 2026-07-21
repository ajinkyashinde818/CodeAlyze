#include<iostream>
using namespace std;

int main(){
    int n;
    long long int c;
    cin >> n >> c;
    long long int x[n];
    int v[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
    }
    long long int maxt[n], maxh[n], maxt2[n], maxh2[n];
    long long int sum;
    long long int sushisumt[n], sushisumh[n];
    for(int i = 0; i < n; i++){
        if(i == 0) sushisumt[i] = v[i];
        else sushisumt[i] = sushisumt[i-1] + v[i];
        sum = sushisumt[i] - x[i];
        if(i == 0){
            if(sum >= 0) maxt[i] = sum;
            else maxt[i] = 0;
        }
        else{
            if(maxt[i-1] < sum) maxt[i] = sum;
            else maxt[i] = maxt[i-1];
        }
        sum = sushisumt[i] - 2*x[i];
        if(i == 0){
            if(sum >= 0) maxt2[i] = sum;
            else maxt2[i] = 0;
        }
        else{
            if(maxt2[i-1] < sum) maxt2[i] = sum;
            else maxt2[i] = maxt2[i-1];
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(i == n-1) sushisumh[i] = v[i];
        else sushisumh[i] = sushisumh[i+1] + v[i];
        sum = sushisumh[i] - (c - x[i]);
        if(i == n-1){
            if(sum >= 0) maxh[i] = sum;
            else maxh[i] = 0;
        }
        else{
            if(maxh[i+1] < sum) maxh[i] = sum;
            else maxh[i] = maxh[i+1];
        }
        sum = sushisumh[i] - 2*(c - x[i]);
        if(i == n-1){
            if(sum >= 0) maxh2[i] = sum;
            else maxh2[i] = 0;
        }
        else{
            if(maxh2[i+1] < sum) maxh2[i] = sum;
            else maxh2[i] = maxh2[i+1];
        }
    }
    long long int max = 0;
    long long int t;
    for(int i = 0; i < n; i++){
        if(i == n-1) t = maxt[i];
        else t = maxt[i] + maxh2[i+1];
        if(t > max) max = t;
    }
    for(int i = 0; i < n; i++){
        if(i == 0) t = maxh[i];
        else t = maxh[i] + maxt2[i-1];
        if(t > max) max = t;
    }
    cout << max << endl;
    return 0;
}
