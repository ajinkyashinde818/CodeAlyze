#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int N;
int a[100010];

int main(){
    cin>>N;
    int minAbs=1000000001;
    int mC=0;
    LL ans=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        minAbs=min(minAbs,abs(a[i]));
        ans+=abs(a[i]);
        if(a[i]<0){
            mC++;
        }
    }
    if(mC%2==1){
        ans-=minAbs*2;
    }
    cout<<ans<<endl;
    return 0;
}
