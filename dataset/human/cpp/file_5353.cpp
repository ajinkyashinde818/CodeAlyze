#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,r;
    cin>>n>>r;
    int rating = 0;
    if(n<10){
        rating = 100 * (10-n);
        rating+=r;
        cout<<rating<<endl;;
    }else{
        rating = r;
        cout<<rating<<endl;
    }
}
