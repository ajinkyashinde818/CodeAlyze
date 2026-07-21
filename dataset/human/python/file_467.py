def larger(x, y):
	if x > y: return x
	return y

N = int(input())
A = list(map(int, input().split()))
dp1 = [A[0], -A[1]-A[0]] #change
dp2 = [A[0], A[1]+A[0]] #notchange
for i in range(2, N):
	newdp1 = larger(dp1[i-1]+2*A[i-1], dp2[i-1]-2*A[i-1]) - A[i]
	newdp2 = larger(dp1[i-1], dp2[i-1]) + A[i]
	dp1.append(newdp1)
	dp2.append(newdp2)
print(larger(dp1[N-1], dp2[N-1]))
