#include<iostream>
using namespace std;

int main(void){
    int n,r=0;

    cin >> n >> r;
    if(n<1||100<n||r<0||4111<r)
        return 0;
    else if(1<=n&&n<=9){
        cout << 100*(10-n)+r << endl;
    }
    else if(10<=n&&n<=100){
        cout << r << endl;
    }
    return 0;
}
