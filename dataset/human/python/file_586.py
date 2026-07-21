def larger(x, y):
	if x > y:
		return x
	return y

N = int(input())
A = list(map(int, input().split()))
dpp = [A[0]]
dpn = [-A[0]]
for i in range(1, N-1):
	nextdpp = larger(dpp[-1]+A[i], dpn[-1]-A[i])
	nextdpn = larger(dpp[-1]-A[i], dpn[-1]+A[i])
	dpp.append(nextdpp)
	dpn.append(nextdpn)
print(larger(dpp[-1]+A[N-1], dpn[-1]-A[N-1]))
