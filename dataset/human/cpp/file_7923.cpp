#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int n;
    vector<LL> a;
    LL tmp_a;
    LL num_sum_b=0;
    LL num_sum_a=0;
    LL min_num;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        num_sum_b+=tmp_a;
        a.push_back(tmp_a);
    }
    num_sum_b-=a[0];
    num_sum_a+=a[0];
    min_num=abs(num_sum_b-num_sum_a);
    for(int i=1; i<n-1; i++){
        num_sum_b-=a[i];
        num_sum_a+=a[i];
        if(abs(num_sum_b-num_sum_a)<min_num){
            min_num=abs(num_sum_b-num_sum_a);
        }
    }

    cout << min_num << endl;

    return 0;
}
