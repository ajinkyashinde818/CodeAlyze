#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MAX=100040;
char s[MAX];
vector<ll> counter;
struct node{
    node *left, *right;
    int val,depth;
    node(){left=NULL, right=NULL,val=0,depth=0;}
};
ll N,L,fin;
node origin;
void dp(node *x){
    if(x->left==NULL && x->right==NULL) return;
    if(x->left ==NULL) counter.push_back(x->depth);
    else dp(x->left );
    if(x->right==NULL) counter.push_back(x->depth);
    else dp(x->right);
}
int main(){
    scanf("%lld%lld",&N,&L);
    for(ll i=0;i<N;i++){
        scanf(" %s",s);
        ll t=strlen(s);
        origin.val=-1;
        node* now=&origin;
        for(ll j=0;j<t;j++){
            node* next=new node();
            if(s[j]=='0'&&now->left==NULL){
                next->val=0,next->depth=now->depth+1;
                now->left=next;
            }
            else if(s[j]=='1'&&now->right==NULL){
                next->val=1,next->depth=now->depth+1;
                now->right=next;
            }
            if(s[j]=='0') now=now->left;
            else if(s[j]=='1') now=now->right;
        }
    }
    dp(&origin);
    for(ll i=0;i<counter.size();i++){
        //printf("%lld\n",counter[i]);
        ll t=L-counter[i];
        fin^=t&(-t);
    }
    if(fin==0) printf("Bob\n");
    else printf("Alice\n");
}
