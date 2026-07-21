#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int r,g,b,n;
    scanf("%d%d%d%d",&r,&g,&b,&n);
    int cnt=0;
    int sum;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            sum=n-(i*r+g*j);
            //cout<<i<<" "<<j<<endl;cout<<sum<<endl;
            if(sum==0||(sum>0&&sum%b==0)) {
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
