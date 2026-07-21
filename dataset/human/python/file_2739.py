from collections import defaultdict

D,G=map( int, raw_input().split() )
P=[ map( int, raw_input().split() ) for i in range(D) ] 

N=10**6
dp= [  float("inf") for i in range(N+1) ]
dp[0]=0

for idx, x  in enumerate(P):
	m=idx+1	#money
	p,c=x[0], x[1]/100
	for i in range(N,-1,-1):
		if dp[i]!=float("inf"):
			for j in range(p,-1,-1):	# j= problems count   , idx = index
				if j==p:
					dp[i+m*j+c]=min( dp[i+m*j+c] , dp[i]+j )
				else:
					dp[i+m*j]=min( dp[i+m*j] , dp[i]+j )



ans=float("inf")

for i in range(G/100,N):
	ans=min(ans, dp[i])

print ans
