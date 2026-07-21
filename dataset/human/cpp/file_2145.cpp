#include<iostream>
#include<vector>

using namespace std;
typedef long long int lli;
int main(){
    int n,v,l=0,p=2;
    long long int ax,min=100000000000,sumz=0;
    cin>>n;
    vector<int> a(n);
    for(;n>0;n--){
        cin>>a[l];
        if(a[l]<0){
            p++;
        }
        sumz=sumz+abs(a[l]);
        if(min>abs(a[l])){
            min=abs(a[l]);
        }

        l++;
        
        
    }
    if(p%2==1){
        ax=sumz-2*min;
    }
    else{
        ax=sumz;
    }
    cout<<ax<<endl;

return(0);
}
