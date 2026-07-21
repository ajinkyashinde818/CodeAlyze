#include<iostream>
#include<string>
#include <vector>
#include <queue>
#include <algorithm>
#include <time.h> 
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int>data;
    //code goes here
    int num, firstNegtiveIdx, minValue=10e8, negativeCtr=0;
    long long sum=0;
    cin >> num;
    for(int i=0;i<num;i++){
        int tmp;
        cin >> tmp;

        if(tmp<0){
            negativeCtr++;
            tmp = tmp*(-1);
        }

        if(tmp < minValue){
            minValue = tmp;
        }

        sum += tmp;

        data.push_back(tmp);
    }

    if((negativeCtr%2) == 1){
        sum = sum - 2*minValue;
    }
    cout<<sum;

}
