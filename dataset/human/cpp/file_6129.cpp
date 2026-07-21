#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    long long n, c;
    cin >> n >> c;
    vector <long long> a;
    vector <long long> b;

    vector <long long> pr1 (n,0);
    vector <long long> pr2 (n,0);
    vector <long long> pr3 (n,0);
    vector <long long> le1 (n,0);
    vector <long long> le2 (n,0);
    vector <long long> le3 (n,0);
    long long t1, t2;
    for (int i=0; i<n; i++){
        cin >> t1 >> t2;
        a.push_back(t1);
        b.push_back(t2);
    }
    long long kal = 0;
    long long cur1 = 0;
    long long cur2 = 0;
    long long maxx = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) {
            cur1 = b[i] - a[i];
            cur2 = b[i] - 2 * a[i];
        }
        else {
            cur1 += b[i] - a[i] + a[i - 1];
            cur2 += b[i] - 2 * a[i] + 2 * a[i - 1];
        }
        pr1[i] = cur1;
        if (cur1 > maxx){
            maxx = cur1;
        }
        pr2[i] = cur2;
        pr3[i] =  maxx;
    }
    cur1 = 0;
    cur2 = 0;
    maxx = 0;
    for (int i=0; i<n; i++){
        if (i == 0) {
            cur1 = b[n-i-1] - (c - a[n-i-1]);
            cur2 = b[n-i-1] - 2*(c - a[n-i-1]);
        }
        else {
            cur1 += b[n-i-1] - (c -a[n-i-1]) + (c - a[n-i]);
            cur2 += b[n-i-1] - 2*(c-a[n-i-1]) + 2*(c -a[n-i]);
        }
        le1[i] = cur1;
        if (cur1 > maxx){
            maxx = cur1;
        }
        le2[i] = cur2;
        le3[i] =  maxx;
    }

    for (int i=0; i<n; i++){
        if (pr1[i] > kal){
            kal = pr1[i];
        }
        if (le1[i] > kal) {
            kal = le1[i];
        }
    }
    for (int i=0; i<n-1; i++){
        if (pr2[i] + le3[n-i-2] > kal){
            kal = pr2[i] + le3[n-i-2];
        }
        if (le2[i] + pr3[n-i-2] > kal){
            kal = le2[i] + pr3[n-i-2];
        }
    }
    cout << kal;
    return 0;
}
