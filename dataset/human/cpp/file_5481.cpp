#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}
inline void write(int x){if (x > 9) write(x/10); putchar(x%10+'0'); }
int n,r;
int main(){
	cin>>n>>r;
	if (n>=10){
		cout<<r<<endl;
		return 0;
	}
	cout << r+100*(10-n) << endl;
    return 0;
}
