#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;



int main() {
   
    long long n;
    vector <long long> a;
    cin >> n;
    for (long long i=0;i<n;i++){
        long long p;
        cin >> p;
        a.push_back(p);
    }
    long long sum = 0;
    vector <long long>::iterator q;
    for (q = a.begin(); q != a.end(); q++){
        sum += *q;
    }
    long long snuke = a[0];
    long long minv = abs(2*snuke - sum);
    for (long long i=1;i<n-1;i++){
        snuke += a[i];
        if(abs(2*snuke - sum) < minv){
            minv = abs(2*snuke-sum);
        }
    }
    cout << minv << endl;
}
