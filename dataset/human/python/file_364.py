from functools import reduce
N = int(input())
A = list(map(int,input().split()))
B = list(map(lambda x: x+0.5, A))
C = reduce(lambda a, b: a*b, B)
D = sorted(list(map(abs, A)))
if C < 0:
	print(sum(D)-2*D[0])
else:
	print(sum(D))
