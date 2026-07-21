#include <bits/stdc++.h>
using namespace std;

long long int N;
long long int C;
long long int x[100001] = {0};
long long int v[100001] = {0};

long long int rtotalv[100001] = {0};
long long int ltotalv[100001] = {0};

long long int rprov[100001] = {0};
long long int lprov[100001] = {0};

long long int rmax(){
    
    long long int eachcal[100001] = {0};
    long long int max = 0;
    for(int i=0;i<N;i++){
        eachcal[i] = rtotalv[i] - x[i];
        if(max < eachcal[i]) max = eachcal[i];
    }
    return max;
}

long long int lmax(){

    long long int eachcal[100001] = {0};
    long long int max = 0;
    for(int i=N-1;i>=0;i--){
        eachcal[i] = ltotalv[i] - (C - x[i]);
        if(max < eachcal[i]) max = eachcal[i];
    }
    return max;
}

long long int rlmax(){
    long long int reachcal[100001] = {0};
    long long int rmax = 0;
    for(int i=0;i<N;i++){
        if((double)x[i] >= (double)(C / 2)) break;
        reachcal[i] = rtotalv[i] - 2 * x[i];
        if(rmax < reachcal[i] + lprov[i+1]) rmax = reachcal[i] + lprov[i+1];
    }
    return rmax;
}

long long int lrmax(){
    long long int leachcal[100001] = {0};
    long long int lmax = 0;
    for(int i=N-1;i>=0;i--){
        if(double(x[i]) <= double(C / 2)) break;
        leachcal[i] = ltotalv[i] - 2 * (C - x[i]);
        if(lmax < leachcal[i] + rprov[i-1]) lmax = leachcal[i] + rprov[i-1];
    }
    return lmax;
}

int main(){
    cin >> N >> C;
    for(int i=0;i<N;i++){
        cin >> x[i] >> v[i];
    }

    rtotalv[0] = v[0];
    for(int i=1;i<N;i++){
        rtotalv[i] = rtotalv[i-1] + v[i];
    }

    ltotalv[N-1] = v[N-1];
    for(int i=N-2;i>=0;i--){
        ltotalv[i] = ltotalv[i+1] + v[i];
    }

    long long int rp = 0;
    for(int i=0;i<N;i++){
        if(rp < rtotalv[i] - x[i]) rp = rtotalv[i] - x[i];
        rprov[i] = rp;
    }

    long long int lp = 0;
    for(int i=N-1;i>=0;i--){
        if(lp < ltotalv[i] - (C - x[i])) lp = ltotalv[i] - (C - x[i]);
        lprov[i] = lp;
    }
    long long int RMAX = rmax();
    long long int LMAX = lmax();
    long long int RLMAX = rlmax();
    long long int LRMAX = lrmax();

    cout << max({RMAX,LMAX,RLMAX,LRMAX}) << endl;
    
    return 0;
}
