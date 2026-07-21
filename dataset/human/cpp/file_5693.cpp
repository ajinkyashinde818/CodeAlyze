#include<iostream>
using namespace std;
typedef long long ll;

int MAX_NODE=100000;
int main()
{
    int N;
    ll L;
    cin >> N >> L;

    int child[MAX_NODE][2];
    fill(child[0], child[0]+MAX_NODE*2, -1);
    int depth[MAX_NODE];
    fill(depth, depth+MAX_NODE, -1);

    depth[0]=0;
    int nodeCount=1;

    for (int i=0;i<N;i++){
        string s;
        cin >> s;
        int prevNode=0;
        int nextNode=-1;

        for (int j=0; j<s.length(); j++){
            int direc = s[j] - '0';

            nextNode = child[prevNode][direc];
            if (nextNode == -1){
                nextNode = nodeCount;
                nodeCount += 1;
                child[prevNode][direc]=nextNode;
                depth[nextNode] = j + 1;
            }
            prevNode = nextNode;
        }
    }

    ll ans = 0;
    for (int i =0;i<nodeCount;i++){
        ll d = L - depth[i];
        if (d > 0) {
            ll g = d&-d;
            for (int j = 0; j < 2; j++) {
                if (child[i][j] == -1) {
                    ans ^= g;
                }
            }
        }
    }

    if (ans!=0){
        cout<<"Alice"<<endl;
    } else {
        cout<<"Bob"<<endl;
    }
    return 0;
}
