#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int n;
    int a[100009]={};
    long long ans=0;
    int m=0;
    int st=0;
    int mi=1000000009;
    int tmp=0;
    int z=0;
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        
        cin >> a[i];
        
    }
    
    for(int i=1; i<=n; i++){
        
        /*
        
        if(a[i]==0){
            
            if(m%2==1){
                
                if(a[])
                
            }
            
            m = 0;
            mi = 1000000009;
            st = i;
            
        } else if(a[i]<0){
            
            m += 1;
            
        }
        
        */
        
        if(a[i]==0){
            
            z = 1;
            
        }
        
        if(a[i]<0){
            
            m += 1;
            
        }
        
        ans += abs(a[i]);
        tmp = abs(a[i]);
        mi = min(mi, tmp);
        
    }
    
    if(z==0&&m%2==1){
        
        ans -= mi * 2;
        
    }
    
    cout << ans << endl;
    
    return 0;
    
}
