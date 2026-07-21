D, G=list(map(int, input().split()))
PC=[0]+[list(map(int, input().split())) for _ in range(D)]

def function(G, i):
	if i==0:
		return 1e9
	n=min(G//(i*100), PC[i][0])
	s=n*i*100
	if n==PC[i][0]:
		s+=PC[i][1]
	if s<G:
		n+=function(G-s, i-1)
	return min(n, function(G,i-1))
print(function(G, D))
