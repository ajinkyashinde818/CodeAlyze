#include <iostream>
using namespace std;
typedef long long ll;
ll m=1e9+7;
int main(void){
    int n;
    ll a[30];
    string s;
    cin>>n>>s;
    fill(a, a+26, 0);
    for(int i=0;i<n;i++){
        a[s[i]-'a']++;
    }
    ll z=a[0]+1;
    for(int i=1;i<26;i++){
        z=(z*(a[i]+1))%m;
    }
    cout<<z-1<<endl;
}
