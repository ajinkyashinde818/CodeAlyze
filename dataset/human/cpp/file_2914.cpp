#include <iostream>
using namespace std;
long long ans;
int n,a,cnt,MIN=1000000007,ok,res;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ans+=abs(a);
        MIN=min(MIN,abs(a));
        if(a<0){
            if(ok==0){
                ok=1;
                cnt++;
            }
            res++;
        }
        else if(a>0&&ok==1){
            ok=0;
            if(res%2==0)cnt--;
            res=0;
        }
    }
    if(res%2==0&&res>0)cnt--;
    if(cnt%2==1)ans-=2*MIN;
    cout<<ans<<endl;
}
