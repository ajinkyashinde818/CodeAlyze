#include<iostream>
using namespace std;

int solve(long long int n){
int ans = 0;
while(n){
ans++;
n >>= 1;
}
return ans;
}

int main(void){
int n,m; cin >> n >> m;
for(int i = 0; i < n; i++){
if(i != 0) cout <<" ";
if(i <= n / 2) cout <<0;
else cout <<m;
}
cout <<endl;
return 0;
}
