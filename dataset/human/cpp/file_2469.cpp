#include<iostream>
#include<vector>
#include<cmath> // abs関数に利用
#include<algorithm> // sort
using namespace std;
// 
// problem https://atcoder.jp/contests/abc125/tasks/abc125_d
// reference http://drken1215.hatenablog.com/entry/2019/04/27/224100
// Algorithm Point:初期の並びを見て負の数が偶数個→並べ替え方の工夫で全部負の数を正の数にできるので絶対値ですべて足す
//                                       奇数個→どうやっても負の数が一つ出来る→絶対値最小のものを負の数、それ以外を絶対値で足す

long long solver(int allNumber,vector<long long> numbers){
    vector<long long> b(allNumber);
    int checkMinus=0;
    for(int j=0;j<allNumber;j++){
        if(numbers.at(j)<0)checkMinus=checkMinus+1;
    }

    bool minusEven=true;
    if(checkMinus%2==1)minusEven=false;
//    cout << "minusEven=" << minusEven << endl;

    for(int j=0;j<allNumber;j++){
        b.at(j)=abs(numbers.at(j));
    }
    sort(b.begin(),b.end());
/**    for (int i = 0; i < allNumber; i++)
    {
        cout << b.at(i) << ",";
    }
    cout << endl;**/
    long long allSum=0;
    for(int j=0;j<allNumber;j++){
        allSum = allSum+b.at(j);
    }
    if(minusEven){
        return allSum;
    }
    else{
        return allSum-b.at(0)*2;// 足しすぎた値(最小値)は残ったマイナスとして処理
    }
    return allSum;
}

int main(void){
    int N;
    long long answer;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    answer = solver(N,A);
    cout << answer << endl;

}
