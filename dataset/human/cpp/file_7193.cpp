#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    long long sum = 0;
    long long init_min = 0;
    int n;
    cin>>n;
    vector<int> cards(n);
    for(int i = 0;i<n;i++){
        cin>>cards[i];
        sum += cards[i];
        init_min += abs(cards[i]);
    }
    long long sunuke=0, arai = sum;
    long long  min = init_min;
    for(int i = 0;i<n-1;i++){
        arai -=  cards[i];
        sunuke += cards[i];
        if (abs(arai-sunuke) < min){min = abs(arai-sunuke);}
    }
    cout<<min<<endl;
}
