#include <bits/stdc++.h> 

using namespace std;

int main(){
    int r,g,b,n,p=0;

    cin >> r >> g >> b >> n;

    int n1, n2, n3;
    if(r==max(r,max(g,b))){
        n1 = r;
        if(g>b){
            n2 = g;
            n3 = b;
        }else{
            n2 = b;
            n3 = g;
        }
    }else if(g>b){
        n1 = g;
        if(r>b){
            n2 = r;
            n3 = b;
        }else{
            n2 = b;
            n3 = r;
        }
    }else{
        n1 = b;
        if(r>g){
            n2 = r;
            n3 = g;
        }else{
            n2 = g;
            n3 = r;
        } 
    }

    int tmp1,tmp2,tmp3;
    for(int i=n/n1;i>=0;i--){
        tmp1 = n - i*n1;
        for(int j=tmp1/n2;j>=0;j--){
            tmp2 = tmp1 - j*n2;
            if(tmp2%n3==0) p++;
        }
    }
    cout << p << endl;
    return 0;
}
