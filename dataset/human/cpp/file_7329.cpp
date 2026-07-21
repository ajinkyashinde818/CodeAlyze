#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    int i, j;
    long long int x, y = 0, min;
    
    cin >> n;
    
    int a[n];
    
    cin >> a[0];
    x = a[0];
    
    for(i = 1; i < n; i++) {
        cin >> a[i];
        y = y + a[i];
    }
    
    min = llabs(x-y);
    
    for(j = 1; j < n-1; j++) {
        x = x + a[j];
        y = y - a[j];
        
        if(llabs(x-y) < min) {
            min = llabs(x-y);
        }
    }
    
    cout << min << endl;
    
    return 0;
}
