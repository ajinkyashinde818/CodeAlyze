#include <bits/stdc++.h>
using namespace std;
int main() {
    // insert code here...
    int n,l,k,p;
    long long answer=0;
    cin>>n;
    k=0;
    cin>>p;
    answer+=abs(p);
    if(p<0)k++;
    for (int i=0; i<n-1; i++) {
        cin>>l;
        if(l<0)k++;
        if(abs(l)<abs(p))p=l;
        answer+=abs(l);
    }
    if (k%2==1) {
        answer-=(abs(p)*2);
    }
    cout<<answer<<endl;
    
    return 0;
}
