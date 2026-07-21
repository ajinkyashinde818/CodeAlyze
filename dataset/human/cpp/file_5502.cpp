#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    int r;
    cin>>n;
    cin>>r;
    if(n>=10){
        cout<<r;
        return 0;
    }
    int internalRating=(r+100*(10-n));
    cout<<internalRating;
    return 0;
}
