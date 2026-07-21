#include<iostream>

using namespace std;

int main(){
        int a,b,c,n,ans,i,ii=0;
        cin >> a >> b >> c >> n;
        for(i=0;i<(n/a)+1;i++){
                for(ii=0;ii<(n/b)+1;ii++){
                        if((n-i*a-ii*b)%c==0&&(n-i*a-ii*b)>=0){
                                ans++;
                        }
                }
        }
        cout << ans;
}
