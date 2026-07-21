#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
int A[2<<17],B[2<<17];
int cA[2<<17],cB[2<<17];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]--;
		cA[A[i]]++;
	}
	for(int i=0;i<N;i++)
	{
		cin>>B[i];
		B[i]--;
		cB[B[i]]++;
	}
	vector<int>id(N);
	for(int i=0;i<N;i++)id[i]=i;
	sort(id.begin(),id.end(),[](int i,int j){return cA[i]+cB[i]>cA[j]+cB[j];});
	if(cA[id[0]]+cB[id[0]]>N)
	{
		cout<<"No"<<endl;
		return 0;
	}
	queue<int>Arest,Brest;
	for(int i=0;i<cA[id[0]];i++)Arest.push(id[0]);
	for(int i=0;i<cB[id[0]];i++)Brest.push(id[0]);
	vector<pair<int,int> >edge;
	for(int i=1;i<N;i++)
	{
		bool witch;
		if(Arest.size()<cB[id[i]])witch=false;
		else if(Brest.size()<cA[id[i]])witch=true;
		else witch=cA[id[i]]>=cB[id[i]];
		if(witch)
		{
			if(Arest.size()<cB[id[i]])return 1;
			for(int j=0;j<cB[id[i]];j++)
			{
				edge.push_back(make_pair(Arest.front(),id[i]));
				Arest.pop();
			}
			for(int j=0;j<cA[id[i]];j++)
			{
				Arest.push(id[i]);
			}
		}
		else
		{
			if(Brest.size()<cA[id[i]])return 1;
			for(int j=0;j<cA[id[i]];j++)
			{
				edge.push_back(make_pair(id[i],Brest.front()));
				Brest.pop();
			}
			for(int j=0;j<cB[id[i]];j++)
			{
				Brest.push(id[i]);
			}
		}
	}
	while(!Arest.empty())
	{
		edge.push_back(make_pair(Arest.front(),-1));
		Arest.pop();
	}
	int i=N;
	while(!Brest.empty()){
		edge[--i].second=Brest.front();
		Brest.pop();
	}
	cout<<"Yes"<<endl;
	sort(edge.begin(),edge.end());
	for(int i=0;i<N;i++)cout<<edge[i].second+1<<(i+1==N?'\n':' ');
}
