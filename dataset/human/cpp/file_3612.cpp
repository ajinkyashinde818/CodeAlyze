#include <iostream>
using namespace std;

int main() {
    int n, b=0, z=0;
    long long a, s=0, m=1e9;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=abs(a);
        m=min(m, abs(a));
        if(a<0)b++;
        if(a==0)z=1;
    }
    if(z==0&&b%2==1){
        s-=m*2;
    }
    cout<<s<<endl;
	return 0;
}
