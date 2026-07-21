#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
ll R, G, B, n;
cin >> R >> G >> B >> n;
ll r, g, b, cont = 0;
for(int i=0; i<=n; i++){
r = i;

for(int j=0; j<=n; j++){
g = j;
b = (n - r*R - g*G)/B;
if(b >= 0 && n - r*R - g*G == b*B){
cont++;
}

}
}
cout << cont;

return 0;
}
