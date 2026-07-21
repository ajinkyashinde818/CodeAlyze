#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v;
    vector<bool> vb;
    v.reserve(n);
    vb.reserve(n - 1);
    for(int i = 0; i < n; ++ i){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    long tmpmax = 0, sum = 0;
    for(int i = 0; i < n; ++ i) sum += ((v[i] < 0)? -v[i] : v[i]);
    for(int i = 0; i < n; ++ i){
        if(i == 0) for(int j = n - 2; 0 <= j; -- j) vb[j] = ((j == n - 2)? (v[j + 1] < 0) : (vb[j + 1] != (v[j + 1] < 0)));
        else vb[i - 1] = ((i == 1)? v[0] < 0 : vb[i - 2] != v[i - 1] < 0);
        if(((i == 0)? vb[0] : ((i == n - 1)? vb[n - 2] : (vb[i - 1] != vb[i]))) == (v[i] < 0)){
            tmpmax = sum;
            break;
        }else{
            tmpmax = max(tmpmax, sum - 2 * abs(v[i]));
        }
    }
    cout << tmpmax << endl;
    
    return 0;
}
