//Bismillahir Rahmanir Raheem
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    vector<long long int> ar(150002);
    int n,sign = 0;
    cin>>n;
    long long a,s=0;
    long long int min = 1000000007;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=abs(a);
        if(abs(a)<min){
            min = abs(a);
        }
        if(a<0) sign++;
    }
    if(sign%2==1) s-=(2*min);
    //cout<<sign<<" "<<min<<endl;

    cout<<s<<endl;
    return 0;
}
