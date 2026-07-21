#include<iostream>

using namespace std;

int main() {
    int a,b,c,n;
    cin >> a>> b>> c>> n;
    
    int cnt =0;
    int cond;

    for(int i=0;i<n/a+1;i++){
       if(a*i > n) break;

        for(int j=0;j<n/b+1;j++){

           if(a*i+b*j > n) break;

            if((n- a*i -b*j) % c == 0) cnt++;
        }
    }

    cout << cnt << endl;
}
