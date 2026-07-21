#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    int k=n;
    if(n<10 && n>=1){
        cout<<(100*(10-k)+r)<<"\n";
    }
    else
        printf("%d\n",r);
    return 0;
}
