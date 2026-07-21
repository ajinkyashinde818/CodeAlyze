#include<cstdio>
#include<queue>
#include<vector>
struct Node{
    int u;
    int ban, left;
    Node(int u,int ban,int left):u(u),ban(ban),left(left){}
    bool operator < (const Node& other)const{
        return ban+left<other.ban+other.left;
    }
};
int a[200005], b[200005];
int cntA[200005], cntB[200005];
int vis[200005];
std::vector<int>pos[200005];
int answer[200005];

void makePair(int u,int v){
    int pu = pos[u][pos[u].size()-1]; pos[u].pop_back();
    int pv = pos[v][pos[v].size()-1]; pos[v].pop_back();
    answer[pu] = v;
    answer[pv] = u;
}

void inNode(Node cur,std::priority_queue<Node>&a,std::priority_queue<Node>&b,std::priority_queue<Node>&c){
    if(cur.ban==0 && cur.left==0) return ;
    else if(cur.ban!=0 && cur.left!=0) a.push(cur);
    else if(cur.ban!=0) b.push(cur);
    else c.push(cur);
}

int min(int a,int b){ return a>b?b:a; }

//put u to pos v
void doPair(int u,int v){
    int p = pos[v][pos[v].size()-1]; pos[v].pop_back();
    answer[p] = u;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){ 
        scanf("%d",&a[i]);
        cntA[a[i]]++;
        pos[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){ 
        scanf("%d",&b[i]);
        cntB[b[i]]++;
    }
    std::priority_queue<Node>Q, qa, qb;
    for(int i = 1; i <= n; i++){
        int u = a[i];
        if(!vis[u]){
            vis[u] = 1;
            if(cntA[u]!=0 && cntB[u]!=0) Q.push(Node(u,cntA[u],cntB[u]));
            else qa.push(Node(u,cntA[u],cntB[u]));
        }
    }
    for(int i = 1; i <= n; i++){
        int u = b[i];
        if(!vis[u]){
            vis[u] = 1;
            if(cntA[u]!=0 && cntB[u]!=0) Q.push(Node(u,cntA[u],cntB[u]));
            else qb.push(Node(u,cntA[u],cntB[u]));
        }
    }
    while(Q.size()>=2){
        Node curU = Q.top(); Q.pop();
        Node curV = Q.top(); Q.pop();
        int u = curU.u, v = curV.u;
        makePair(u,v);
        curU.ban--, curU.left--;
        curV.ban--, curV.left--;
        inNode(curU,Q,qa,qb);
        inNode(curV,Q,qa,qb);
    }
    Node only = Node(-1,0,0);
    if(Q.size()!=0) only = Q.top();
    int ok = 1;
    while(only.ban!=0){
        if(qb.size()==0){
            ok = 0;
            break;
        }
        else{
            Node cur = qb.top(); qb.pop();
            int time = min(only.ban,cur.left);
            only.ban -= time;
            cur.left -= time;
            if(cur.left!=0) qb.push(cur);
            for(int i = 0; i < time; i++){
                doPair(cur.u,only.u);
            }
        }
    }
    if(ok==0){ 
        printf("No\n");
        return 0;
    }
    while(only.left!=0){
        if(qa.size()==0){
            ok = 0;
            break;
        }
        else{
            Node cur = qa.top(); qa.pop();
            int time = min(only.left,cur.ban);
            only.left -= time;
            cur.ban -= time;
            if(cur.ban!=0) qa.push(cur);
            for(int i = 0; i < time; i++){
                doPair(only.u,cur.u);
            }
        }
    }
    if(ok==0){ 
        printf("No\n");
        return 0;
    }
    while(qa.size()!=0){
        if(qb.size()==0){
            ok = 0;
            break;
        }
        Node only = qa.top(); qa.pop();
        while(only.ban!=0){
            if(qb.size()==0){
                ok = 0;
                break;
            }
            else{
                Node cur = qb.top(); qb.pop();
                int time = min(only.ban,cur.left);
                only.ban -= time;
                cur.left -= time;
                if(cur.left!=0) qb.push(cur);
                for(int i = 0; i < time; i++){
                    doPair(cur.u,only.u);
                }
            }
        }
    }
    if(!ok) printf("No\n");
    else{
        printf("Yes\n");
        for(int i = 1; i <= n; i++) printf("%d ",answer[i]);
        printf("\n");
    }
    return 0;
}
