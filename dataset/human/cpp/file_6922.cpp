#include <bits/stdc++.h>
using namespace std;

signed main(void){
    
    long long N,a,maxA=0;
    vector<long long> A,B;
    vector<long long> As(200020,0),Bs(200020,0);
    
    cin >> N;
    for(long long i=0;i<N;i++){
        cin >> a;
        maxA = max(maxA,a);
        A.push_back(a);
        As[a]++;
    }
    for(long long i=0;i<N;i++){
        cin >> a;
        maxA = max(maxA,a);
        B.push_back(a);
        Bs[a]++;
    }
    
    
    //AとBに合わせてN+1個以上ある要素がある場合、鳩の巣原理よりNG
    for(long long i=0;i<=maxA;i++){
        if(As[i]+Bs[i]>N){
            cout << "No" << endl;
            return 0;
        }
    }
    //そうでなければ必ず構成できる
    cout << "Yes" << endl;
    
    //Bを降順にしておく
    reverse(B.begin(),B.end());
    
    //この時点でかぶってるのは高々区間１つ
    long long T = -1;
    for(long long i=0;i<N;i++){
        if(A[i]==B[i]){
            T=A[i];
            break;
        }
    }
    
    //かぶりがなければそこで終了してよい
    if(T==-1){
        for(long long i=0;i<N;i++){
            cout << B[i] << " ";
        }
        cout << endl;
        return 0;
    }
    
    //かぶりがある
    //まずBでかぶってる部分を限界までBの先頭に写す
    long long ib=0;
    for(long long i=0;i<N;i++){
        if(A[i]==B[i]){
            swap(B[ib],B[i]);
            ib++;
        }
    }
    
    //この時点でもまだ被りがある場合、Aでかぶってる部分を限界までAの最後尾に移す
    long long ia=N-1;
    for(long long i=0;i<N;i++){
        if(A[i]==B[i]){
            swap(A[ia],A[i]);
            ia--;
        }
    }
    //ここまでで全てさばけているはず(同じ数は高々N個しかないので)
    
    //答えはAでソートしておく
    vector<pair<long long,long long>> Ans;
    for(long long i=0;i<N;i++){
        Ans.push_back({A[i],B[i]});
        if(A[i]==B[i]){
            //もし違法があったらREを吐く
            assert(false);
        }
    }
    sort(Ans.begin(),Ans.end());
    
    for(long long i=0;i<N;i++){
        cout << Ans[i].second << " ";
    }
    cout << endl;
    
    return 0;
}
