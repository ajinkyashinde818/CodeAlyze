#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,i;
    long long a[100010],x=0,y=-1,s=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
        if(a[i]<0){
            x++;
            a[i]=-a[i];
        }
        s+=a[i];
        if(a[i]<y || y==-1)
            y=a[i];
    }
    if(x%2!=0)
        cout << s-2*y << endl;
    else
        cout << s << endl;
    return 0;
}
