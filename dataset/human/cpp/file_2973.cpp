#include <bits/stdc++.h>
using namespace std;

int main(){
int n, neg = 0;
bool c = false;
long long int sum = 0;
cin >> n;
vector <long long int> a(n+1);
vector <long long int> b;
for (int i = 1; i<=n;i++){
cin >> a[i];
if (a[i] < 0){
++neg;
}
if (a[i] == 0){
c = true;
}
b.push_back(abs(a[i]));
}
sort(b.begin(),b.end());
for (int j = 0; j < n; ++j){
sum += b[j];
}
if (neg % 2 == 1){
if (!c){
sum -= 2 * b[0];
}
}
cout << sum << "\n";
return 0;
}
