#include <iostream>
using namespace std;


int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
int res=0;
for(int i=0;i<=N;i++){
for(int j=0;j<=N;j++){
int temp=N-R*i-G*j;
if(temp>=0 && temp%B==0){res++;}
}}



    cout << res << endl;
return 0;
}
