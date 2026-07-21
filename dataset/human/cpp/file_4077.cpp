#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
const double eps=1e-10;
struct qnode{
	int id;
	double val;
	bool operator<(qnode b)const{
		return val>b.val;
	}
};
struct node{
	int to,nxt;
	double weigh;
}edge[3001000];
struct Point{
	int x,y,r;
}s,t,a[2010];
double dis[2010];
int head[2010],S,T,vis[2010];
int n,m,x,y,z,cnt;
std::priority_queue<qnode>q;
double dist(Point a,Point b){
	return sqrt(1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y));
}
void addedge(int x,int y,double z){
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
	edge[cnt].weigh=z;
}
void Dijkstra(){
	for(int i=S;i<=T;i++)
		dis[i]=1e100;
	dis[S]=0;
	memset(vis,false,sizeof(vis));
	q.push((qnode){S,0});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(int i=head[x];i;i=edge[i].nxt){
			int upup=edge[i].to;
			dis[upup]=std::min(dis[upup],dis[x]+edge[i].weigh);
			if(!vis[upup])q.push((qnode){upup,dis[upup]});
		}
	}
}
int main(){
	scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
	S=0,T=n+1;
	addedge(S,T,dist(s,t));
	addedge(T,S,dist(s,t));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			double Dis=dist(a[i],a[j]);
			Dis-=a[i].r+a[j].r;
			if(Dis<eps)addedge(i,j,0),addedge(j,i,0);
			else addedge(i,j,Dis),addedge(j,i,Dis);
		}
	for(int i=1;i<=n;i++){
		double Dis=dist(s,a[i]);
		Dis-=a[i].r;
		if(Dis<eps)addedge(S,i,0),addedge(i,S,0);
		else addedge(i,S,Dis),addedge(S,i,Dis);
		Dis=dist(t,a[i]);
		Dis-=a[i].r;
		if(Dis<eps)addedge(T,i,0),addedge(i,T,0);
		else addedge(i,T,Dis),addedge(T,i,Dis);			
	}
	Dijkstra();
	printf("%.10lf\n",dis[T]);
	return 0;
}
