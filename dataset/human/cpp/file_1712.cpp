#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k = (int)ceil(sqrt(2*n));
    if(k*(k-1)/2!=n) {
        cout << "No" << endl;
        exit(0);
    }
    else {
        cout << "Yes" << endl;
        cout<< k<<endl;
    }
    int init = 1;
    int q = init;
    cout<<k-1<<" "<<q<<" ";
    for(int d = 2;d<k;d++){
        q+=d;
        cout<<q<<" ";
    }
    cout<<endl;
    int i = 0;
    for(;i<k-1;i++){
        init = init+i;
        vector<int> temp;
        int temp_init = init;
        temp.push_back(temp_init);
        for(int j = i;j>0;j--) {
            temp_init++;
            temp.push_back(temp_init);
        }
        for(int m = i+1;m<k-1;m++){
            temp_init+=m;
            temp.push_back(temp_init);
        }
        cout<<k-1<<" ";
        for(int p = 0;p<k-1;p++)
            cout<<temp[p]<<" ";
        cout<<endl;
    }

}
